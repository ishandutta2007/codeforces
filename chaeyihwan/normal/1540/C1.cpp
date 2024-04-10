#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int c[102], b[102], dp[10002][102];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<=n;i++) cin >> c[i];
    for(int i=1;i<n;i++) cin >> b[i];
    int q; cin >> q;
    ll x; cin >> x;

    for(int i=max(0LL, x);i<=c[1];i++) dp[i][1] = 1;
    ll sum = x;
    x += b[1];
    sum += x;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=10000;j++)
        {
            for(int k=0;k<=c[i];k++)
            {
                if(sum <= j + k && j + k <= 10000)
                {
                    dp[j+k][i] += dp[j][i-1];
                    dp[j+k][i] %= mod;
                }
            }
        }
        x += b[i];
        sum += x;
    }
    ll ans = 0;
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=10;j++) cout << dp[j][i] << " ";
        cout << "\n";
    }
    */
    for(int i=0;i<=10000;i++) ans = (ans + dp[i][n])%mod;
    cout << ans;
}