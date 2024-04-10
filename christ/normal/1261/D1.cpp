#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MN = 2e3+2, MOD = 998244353;
int dp[MN][MN<<1];
int main () {
    int n,k;
    scanf ("%d %d",&n,&k);
    vector<int> a(n+1), b(n+1);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a[i]);
        b[i%n+1] = a[i];
    }
    dp[0][n] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n<<1); j++) {
            if (a[i] == b[i]) dp[i][j] = dp[i-1][j]*1LL*k%MOD;
            else {
                dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%MOD;
                dp[i][j] = (dp[i][j]+(dp[i-1][j]*1LL*max(0,k-2)%MOD))%MOD;
            }
        }
    }
    int ans = 0;
    for (int i = n+1; i <= (n << 1); i++) ans = (ans + dp[n][i])%MOD;
    printf ("%d\n",ans);
    return 0;
}