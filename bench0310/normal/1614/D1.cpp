#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int N=5000000;
    vector<ll> dp(N+1,0);
    vector<ll> cnt(N+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        for(int j=1;j*j<=a;j++)
        {
            if(a%j) continue;
            cnt[j]++;
            if(j*j<a) cnt[a/j]++;
        }
    }
    ll res=0;
    for(int i=N;i>=1;i--)
    {
        dp[i]=i*cnt[i];
        for(int j=2*i;j<=N;j+=i) dp[i]=max(dp[i],dp[j]+i*(cnt[i]-cnt[j]));
        res=max(res,dp[i]);
    }
    cout << res << "\n";
    return 0;
}