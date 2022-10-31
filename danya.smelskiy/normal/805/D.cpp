#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
string s;
long long lastkol,ans;
long long dp[1000005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    dp[1]=1;
    for (int i=2;i<=s.size();++i)
        dp[i]=(dp[i-1]*2+1)%md;
    for (int i=1;i<=s.size();++i){
        if (s[i-1]=='a') ++lastkol;
        else {
            ans=(ans+(dp[lastkol]))%md;
        }
    }
    cout<<ans<<endl;
}