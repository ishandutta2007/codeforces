#include <bits/stdc++.h>
using namespace std;
string s,ss;
long long ans;
long long kol[1000];
int main(){
    cin>>s;
    for (int i=0;i<s.size();++i)
        ++kol[s[i]];
    ans=kol['B'];
    ss="Bulbasaur";
    for (int i=1;i<ss.size();++i)
        if (ss[i]=='a' || ss[i]=='u') ans=min(ans,kol[ss[i]]/2);
        else ans=min(ans,kol[ss[i]]);
    cout<<ans;
}