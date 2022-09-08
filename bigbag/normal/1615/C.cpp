/**
 *  created: 24/12/2021, 16:55:53
**/

#include <bits/stdc++.h>

using namespace std;

const int inf = 1000111222;

int t, n;
string a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        int ans = inf;
        {
            int ones = 0, zeros = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] != b[i]) {
                    ones += a[i] == '1';
                    zeros += a[i] == '0';
                }
            }
            if (ones == zeros) {
                ans = min(ans, ones + zeros);
            }
        }
        {
            int ones = 0, zeros = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] == b[i]) {
                    ones += a[i] == '1';
                    zeros += a[i] == '0';
                }
            }
            if (ones == zeros + 1) {
                ans = min(ans, ones + zeros);
            }
        }
        if (ans == inf) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}