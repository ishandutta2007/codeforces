#include <bits/stdc++.h>
 
using namespace std;
 
string s;
bool h = true;
 
bool f(string s){
    for(int i = 0; i < s.length(); i++){
        if(islower(s[i])){
            h = false;
            break;
        }
    }
    if(h){
        return true;
    }
    if(islower(s[0])){
        for(int i = 1; i < s.length(); i++){
            if(islower(s[i])){
                return false;
            }
        }
    }else{
        return false;
 	}
    return true;
}
 
int main(){
    cin >> s;
    if(f(s)){
        for(int i = 0; i < s.length(); i++){
            if(islower(s[i]))
                s[i] = toupper(s[i]);
            else if(isupper(s[i]))
                s[i] = tolower(s[i]);
        }
    }
    cout << s;
}