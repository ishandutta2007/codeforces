/**
 *  created: 17/10/2021, 14:19:51
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, m, q;
string s[max_n];
int sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int j = 1; j < m; ++j) {
        bool ok = 0;
        for (int i = 1; i < n; ++i) {
            ok |= (s[i - 1][j] == 'X' && s[i][j - 1] == 'X');
        }
        sum[j] = ok;
        sum[j] += sum[j - 1];
    }
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (sum[r] - sum[l] > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}