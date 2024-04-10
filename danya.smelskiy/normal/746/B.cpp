#include <bits/stdc++.h>
using namespace std;

int n,last;
string s,ss;
int main(){
    cin>>n>>s;
    if (s.size()%2==1) last=0;
    else last=1;
    for (int i=0;i<s.size();++i){
        if (last==1) ss=s[i]+ss;
        else ss=ss+s[i];
        last=(last+1)%2;
    }
    cout<<ss;
}