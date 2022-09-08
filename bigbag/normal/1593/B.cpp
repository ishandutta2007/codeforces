/**
 *  created: 13/10/2021, 17:37:58
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int t;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> s;
        int ans = inf;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i + 1; j < s.size(); ++j) {
                long long x = 0;
                for (int k = 0; k <= j; ++k) {
                    if (k < i || k == i || k == j) {
                        x = x * 10 + s[k] - '0';
                    }
                }
                if (x && x % 25 == 0) {
                    ans = min<int>(ans, (j - i - 1) + (s.size() - j - 1));
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}