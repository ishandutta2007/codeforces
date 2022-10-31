#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
long long n;
long long p[10005];
long long dp[10005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>p[i];
    for (int i=2;i<=n+1;++i) {
        dp[i]=dp[i-1]+dp[i-1]+2-dp[p[i-1]];
        if (dp[i]<0) dp[i]+=md;
        else dp[i]%=md;
    }
    cout<<dp[n+1];
}