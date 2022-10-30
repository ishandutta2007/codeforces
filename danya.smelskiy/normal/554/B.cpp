#include <bits/stdc++.h>
using namespace std;
long long n;
string s[1000];
long long kol,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>s[i];
    for (int i=1;i<=n;++i){
        kol=0;
        for (int j=1;j<=n;++j){
            if (s[j]==s[i]) ++kol;
        }
        ans=max(ans,kol);
    }
    cout<<ans;
}