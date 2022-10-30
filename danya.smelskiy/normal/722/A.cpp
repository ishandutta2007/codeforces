#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
    cin>>n;
    cin>>s;
    if (n==12){
        if (s[0]>'1' && s[1]>'0') s[0]='0';
        else if (s[0]>'1') s[0]='1';
        if (s[0]=='0' && s[1]=='0') s[1]='1';
        if (s[0]=='1' && s[1]>'2') s[1]='2';
    } else {
        if (s[0]>'2') s[0]='1';
        if (s[0]=='2' && s[1]>='4') s[1]='0';
    }
    if (s[3]>'5') s[3]='5';
    cout<<s;
}