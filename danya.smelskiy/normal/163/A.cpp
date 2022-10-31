#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;

string s,ss;
long long ans;
long long dp[5001][5001];

int main(){
    cin>>s>>ss;
    int n=s.size(),m=ss.size();
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            dp[i][j]=dp[i][j-1];
            if (s[i-1]==ss[j-1]) dp[i][j]=(dp[i][j]+dp[i-1][j-1]+1)%md;
        }
    }
    for (int i=1;i<=n;++i)
        ans=(ans+dp[i][m])%md;
    cout<<ans;
}