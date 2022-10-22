#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

int a[102], b[102];
int dp[20002];
int tmp[20002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) cin >> b[i];

        int sum = 0;
        for(int i=1;i<=n;i++) sum += a[i] + b[i];

        for(int i=1;i<=sum;i++) dp[i] = 0;
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++) tmp[j] = 0;
            for(int j=0;j<=sum-a[i];j++) if(dp[j]) tmp[j+a[i]] = 1;
            for(int j=0;j<=sum-b[i];j++) if(dp[j]) tmp[j+b[i]] = 1;

            for(int j=0;j<=sum;j++) dp[j] = tmp[j];
        }

        ll k = sum/2;
        for(k=sum/2;k>=0;k--) if(dp[k] || dp[sum-k]) break;
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += (a[i]*a[i]) + (b[i]*b[i]);
        ans *= n-2;

        ans += k*k + (sum-k)*(sum-k);

        cout << ans << "\n";
    }
}