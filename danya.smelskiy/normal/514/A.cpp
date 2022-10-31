#include <bits/stdc++.h>
using namespace std;
string s;
bool tt;
bool t;
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]=='5') s[i]='4';
        else if (s[i]=='6') s[i]='3';
        else if (s[i]=='7') s[i]='2';
        else if (s[i]=='8') s[i]='1';
        else if (s[i]=='9' && tt==true) s[i]='0';
        if (s[i]!='0') tt=true;
    }
    for (int i=0;i<s.size();++i){
        if (s[i]!='0') t=true;
        if (t==true) cout<<s[i];
    }
}