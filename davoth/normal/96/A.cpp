#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    string s;
    cin>>s;
    if(s.size()<7){
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<s.size()-6;i++){
        if(s[i]==s[i+1]&&s[i]==s[i+2]&&s[i]==s[i+3]&&s[i]==s[i+4]&&s[i]==s[i+5]&&s[i]==s[i+6]){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}