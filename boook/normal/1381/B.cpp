// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 4040
#define inf 0x3f3f3f3f

int t, n, x[maxn], dp[maxn][maxn], v[maxn];

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n;
        n = n + n;
        for (int i = 1; i <= n; ++ i) cin >> x[i];
        for (int i = 0; i <= n; ++ i) {
            for (int j = 0; j <= n; ++ j) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        int now = n, nn = 1;
        while (now != 0) {
            int big = 1;
            for (int i = 1; i <= now; ++ i) if (x[i] > x[big]) big = i;
            int val = now - big + 1;
//            cout << "val = " << val << endl;
            for (int i = 1; i <= n / 2; ++ i) {
                dp[nn][i] = max(dp[nn][i], dp[nn - 1][i]);
                dp[nn][i] = max(dp[nn][i], dp[nn - 1][i - val]);
            }
            v[nn] = val;
            nn ++;
            now = big - 1;
        }
        if (dp[nn - 1][n / 2]) cout << "YES" << "\n";
        else cout << "NO\n"; 
    }
    return 0;
}