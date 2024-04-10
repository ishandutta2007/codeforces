#include <bits/stdc++.h>
using namespace std;
bool t;
string s,s1,s2;
int used[1000];
int main(){
    cin>>s>>s1>>s2;
    for (int i=0;i<s.size();++i)
        ++used[s[i]];
    for (int i=0;i<s1.size();++i)
        ++used[s1[i]];
    for (int i=0;i<s2.size();++i){
        --used[s2[i]];
        if (used[s2[i]]<0) t=true;
    }
    if (t==true || (s.size()+s1.size()!=s2.size())) cout<<"NO";
    else cout<<"YES";
}