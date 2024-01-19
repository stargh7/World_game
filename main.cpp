//
//  main.cpp
//  wordle_game
//
//  Created by Sagar Basavaraju on 1/1/24.
//
#include <iostream>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
//Stating whether the string exists or not:
vector<char> alphabet {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector <string> full_dictionary;
bool string_exist(const string & string_1) {
    for (char c : string_1) {
        if (find(alphabet.begin(), alphabet.end(), c) == alphabet.end()) {
            return false;
        }
    }
    return string_1.length()==5;
}

// number of attempts being made:
int attempts = 0;
// Function for defining a random target string to check based on used-input:
vector<char> possible_letters {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
string string_random(int length){
    string random_letters;
    for(int i=0;i<length;i++){
        random_letters += possible_letters[rand() % possible_letters.size()];
    }
    return random_letters;
}
// String checker comparison checking whether randomized target string == users string 1:
void string_checker(string string_1, string string_target){
    int check_trys = 5;
    vector <char> string_chars;
    vector <string> string_strings;
    string current_string;
    for(int tries = 0; tries<check_trys;tries++){
        bool string_matched{false};
        auto num= string_1.length();
        auto num2 = string_target.length();
        for (int i = 0;i < num && i < num2; i++){
            if(string_1.at(i) == string_target.at(i)){
                string_chars.push_back(string_1.at(i));
            }
            else {
                if(string_1.length() == 5){
                    cout<<"Enter a string:"<<endl;
                    cin >> string_1;
                    auto new_length = string_1.length();
                    string_chars.clear();
                    for(int i = 0; i < new_length && i < num2; i++){
                        if(string_1.at(i) == string_target.at(i)){
                            string_chars.push_back(string_1.at(i));
                        }
                    }
                    attempts++;
                    break;
                }
                else{
                cout<<"please try again and make sure it is 5 characters long"<<endl;
                    cin>>string_1;
                    attempts++;
                    string_chars.clear();
                    tries = -1;
                    break;
                }
            }
        }
        string current_string(string_chars.begin(),string_chars.end());
        string_strings.push_back(current_string);
        if(current_string == string_target){
            string_matched=true;
            cout<<"matched"<<endl;
            break;
        }
    }
    if(string_1 != string_target){
        cout<<"After 5 tries string 1 does not match"<<endl;
    }
}

//tallying points from the user depending on how many letters user gets correct
int counting(string string_1,string string_target){
    static int total = 0;
            if(string_1 == string_target){
                attempts++;
            }
    if(attempts > 10){
        total -= 5;
    }
    else{
        total += 5;
    }
    return total;
        }

//checking if dictionary matches users input
int f(string input){
    long int x = 0;
    while (x < full_dictionary.size()){
        for(int i = 1; i < 5; i++){
            cout<<full_dictionary[i].at(x)<<endl;
            if(full_dictionary[i].at(x) != input.at(x)){
                break;
            }
            else if(full_dictionary[i].at(x) == input.at(x)){
                return 1;
            }
        }
        x++;
    }
    return 0;
}


//Asking for users input and retrival of target string through function:
int main(){
    /*
    string organizeFile =
    fstream infs;
    infs.open(organizeFile);
    if(infs.fail()){
        cout << "Fail to open: " + organizeFile << endl;
        exit(1);
    }
    
    int length = 0;
    string line;
    while (!infs.eof()){
        getline(infs,line,'\n');
        full_dictionary.push_back(line);
        line = "";
        length++;
    }
    srand(static_cast<int>(time(NULL)));
    string solution =  full_dictionary[rand() % length];
    */
    //user options:
    int option_1 = 1;
    int option_2 = 2;
    int option_3 = 3;
    int option_4 = 4;
    int user;
    string string_1;
    string string_word = string_random(5);
    int user_input_no = 0;
    cout<<"WELCOME TO WORDLE GAME: "<<"\n"<<endl;
    cout<<"Please enter an option 1 for yes, 0 for no "<<endl;
    cin >> user;
    if(user == 1){
        
        do{
            cout<<" Enter an option: "<<"\n"<< option_1 <<" to start"<<"\n"<<option_2<<" to view score"<<"\n"<<option_3<<" restart "<<"\n"<<option_4<<" to quit"<<"\n";
            cin >> user;
            if(user == option_1){
                cout << "Enter a string that is 5 letters: " << endl;
                cin >> string_1;
                if(string_exist(string_1)==true)
                   {
                    srand(static_cast<int>(time(NULL)));
                    cout<<string_word<<endl;
                       string_checker(string_1,string_word);
                       string_word = string_random(5);
                       attempts++;
                }
                else if(string_exist(string_1) == false){
                    cout<<"Not a valid word,please try again: "<<endl;
                    cin>>string_1;
                    if(string_exist(string_1) == true){
                        srand(static_cast<int>(time(NULL)));
                        cout<<string_word<<endl;
                        string_checker(string_1,string_word);
                        attempts++;
                    }
                }
            }
            else if(user == option_2) {
                static int result;
                result = counting(string_1,string_word);
                cout<<"Score: "<<result<<endl;
            }
            else if(user == option_3){
                EXIT_FAILURE;
            }
        }
        while(user != option_4 && user != user_input_no);
    }
        //generating a random string:
        //checking the strings:
}
