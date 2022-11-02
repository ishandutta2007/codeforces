// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define F first
#define S second
#define endl "\n"
//--------------------------------------
#define maxn 400900
#define inf 0x3f3f3f3f

int t, n, dp[maxn];
string s;

int32_t main(){
	cin.tie(0), cout.sync_with_stdio(0);
    cin >> t;
    while (t --) {
        cin >> n >> s, s = " " + s;
        for (int i = 1; i <= n; ++ i) s += s[i];
    
        int ans = n + 10;
        for (int f = 1; f <= n; ++ f) {
            if (f > 6) break;
            for (int i = 1; i <= n + n; ++ i) dp[i] = inf;
            // from f + 0 ~ f + n - 1
            dp[f - 1] = 0;
            for (int i = f + 1; i <= f + n - 1; ++ i) {
                if (i - 2 >= f - 1) dp[i] = min(dp[i], dp[i - 2] + (s[i - 1] != 'R') + (s[i - 0] != 'L'));
                if (i - 3 >= f - 1) dp[i] = min(dp[i], dp[i - 3] + (s[i - 2] != 'R') + (s[i - 1] != 'R') + (s[i - 0] != 'L'));
                if (i - 3 >= f - 1) dp[i] = min(dp[i], dp[i - 3] + (s[i - 2] != 'R') + (s[i - 1] != 'L') + (s[i - 0] != 'L'));
                if (i - 4 >= f - 1) dp[i] = min(dp[i], dp[i - 4] + (s[i - 3] != 'R') + (s[i - 2] != 'R') + (s[i - 1] != 'L') + (s[i - 0] != 'L'));
            }
            ans = min(ans, dp[f + n - 1]);
        }

        cout << ans << endl;
    }
    return 0;
}