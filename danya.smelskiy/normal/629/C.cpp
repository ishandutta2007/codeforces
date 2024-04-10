#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,m;
string s;
long long ans;
long long dp[2005][2005];
int bal;
int mn;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for (int i=1;i<=s.size();++i) {
        if (s[i-1]=='(') ++bal;
        else --bal;
        mn=min(mn,bal);
    }
    dp[0][0]=1;
    for (int i=0;i<n-m;++i)
    for (int j=0;j<=2000;++j) {
        if (j) dp[i+1][j-1]=(dp[i+1][j-1]+dp[i][j])%md;
        if (j<2000) dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%md;
    }
    mn=abs(mn);
    for (int i=0;i<=n-m;++i)
    for (int j=mn;j<=2000;++j) if (dp[i][j]) {
        int bal2=bal+j;
        if (bal2<=2000) ans=(ans+dp[i][j]*dp[n-m-i][bal2])%md;
    }
    cout<<ans;
}