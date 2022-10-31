#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
const int MOD = 1000000007;

int n;
int brr[N], crr[N], dp[N][N*N];
int sb[N], ssb[N];

signed main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> crr[i];
    for(int i = 1; i<=n-1; i++)
        cin >> brr[i];
    for(int i = 1; i<=n-1; i++)
        sb[i] = sb[i-1]+brr[i];
    for(int i = 1; i<=n-1; i++)
        ssb[i] = ssb[i-1]+sb[i];
    int q; cin >> q; 
    int x; cin >> x;
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = max(0ll, i*x+ssb[i-1]); j<N*N; j++){
            for(int k = 0; k<=crr[i]; k++){
                int val = j-k; 
                if(val < 0) continue;
                if(val < (i-1)*x+ssb[max(0ll, i-2)]) continue;
                dp[i][j] = dp[i][j]+dp[i-1][val];
                if(dp[i][j] >= MOD) dp[i][j] -= MOD;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<N*N; i++)
        ans = (ans+dp[n][i])%MOD;
    cout << ans << endl;
}