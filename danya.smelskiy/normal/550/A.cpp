#include <bits/stdc++.h>
using namespace std;
string s;
bool t,t2;
int main(){
    cin>>s;
    for (int i=0;i<=s.size();++i){
        if (s[i]=='A' && s[i+1]=='B' && t==false){
            t=true;
            for (int j=i+2;j<s.size();++j){
                if (s[j]=='B' && s[j+1]=='A'){
                    cout<<"YES";
                    return 0;
                }
            }
        }
        if (s[i]=='B' && s[i+1]=='A' && t2==false){
            t2=true;
            for (int j=i+2;j<s.size();++j){
                if (s[j]=='A' && s[j+1]=='B'){
                    cout<<"YES";
                    return 0;
                }
            }
        }
    }
    cout<<"NO";
}