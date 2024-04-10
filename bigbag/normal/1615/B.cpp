/**
 *  created: 24/12/2021, 16:37:43
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;
const int max_b = 20;

int t, l, r, cnt[max_n][max_b];

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < max_n; ++i) {
        for (int b = 0; b < max_b; ++b) {
            cnt[i][b] = cnt[i - 1][b];
            cnt[i][b] += get_bit(i, b);
        }
    }
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int ans = 0;
        for (int b = 0; b < max_b; ++b) {
            ans = max(ans, cnt[r][b] - cnt[l - 1][b]);
        }
        cout << r - l + 1 - ans << "\n";
    }
    return 0;
}