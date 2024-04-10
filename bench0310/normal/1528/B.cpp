#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n+1,0);
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) d[j]++;
    vector<ll> dp(n+1,0);
    ll sum=0;
    const ll mod=998244353;
    for(int i=1;i<=n;i++)
    {
        dp[i]=sum+d[i];
        sum=(sum+dp[i])%mod;
    }
    cout << dp[n] << "\n";
    return 0;
}