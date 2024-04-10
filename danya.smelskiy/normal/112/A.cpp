#include <bits/stdc++.h>
using namespace std;
string s,s1;
int main(){
    cin>>s>>s1;
    if (s.size()>s1.size()) cout<<"1";
    else if (s.size()<s1.size())cout<<"-1";{
    for (int i=0;i<s.size();++i){
    if (s[i]>='A' && s[i]<='Z') s[i]=s[i]+32;
    if (s1[i]>='A' && s1[i]<='Z') s1[i]=s1[i]+32;
    }
    if (s>s1) cout<<"1";
    else if (s<s1) cout<<"-1";
    else cout<<"0";
    }
}