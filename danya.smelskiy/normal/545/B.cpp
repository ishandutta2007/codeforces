#include <bits/stdc++.h>
using namespace std;
string s,s2,ans;
long long kol,now;
int main(){
    cin>>s>>s2;
    for (int i=0;i<s.size();++i)
        ans+=".";
    for (int i=0;i<s.size();++i){
        if (s[i]==s2[i]) {ans[i]=s[i]; ++kol;}
    }
    kol=s.size()-kol;
    if (kol%2!=0){
        cout<<"impossible";
        return 0;
    }
    for (int i=0;i<s.size();++i) if (ans[i]=='.'){
        if (now<kol/2){
            ++now;
            ans[i]=s[i];
        } else ans[i]=s2[i];
    }
    cout<<ans;
}