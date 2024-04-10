/**
 *  created: 17/03/2021, 18:38:11
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5055, inf = 1000111222;

int t, n, tag[max_n], s[max_n];
long long dp_up[max_n], mx[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> tag[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        memset(dp_up, 0, sizeof(dp_up));
        for (int i = 1; i < n; ++i) {
            memset(mx, 0, sizeof(mx));
            for (int from = 0; from < i; ++from) {
                if (tag[from] != tag[i]) {
                    long long res = abs(s[from] - s[i]) + dp_up[from];
                    dp_up[i] = max(dp_up[i], res);
                    if (from) {
                        mx[from - 1] = max(mx[from - 1], res);
                    }
                }
            }
            for (int j = i - 1; j >= 0; --j) {
                mx[j] = max(mx[j], mx[j + 1]);
                if (tag[j] != tag[i]) {
                    dp_up[j] = max(dp_up[j], mx[j] + abs(s[i] - s[j]));
                }
            }
        }
        long long ans = *max_element(dp_up, dp_up + n);
        cout << ans << "\n";
    }
    return 0;
}