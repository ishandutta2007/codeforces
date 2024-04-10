#include <bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
    cin>>s>>s1;
    for (int i=s.size();i>0;--i){
        if (s[i-1]==s1[i-1] && s[i-1]=='1') s[i-1]='0';
        else if (s[i-1]=='0' && s1[i-1]=='1') s[i-1]='1';
    }
    cout<<s;
}