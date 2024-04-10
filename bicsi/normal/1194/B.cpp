#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    while (q--) {
        int n, m; cin >> n >> m;
        vector<string> mat(n);
        for (int i = 0; i < n; ++i)
            cin >> mat[i];

        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == '*') {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }

        int ans = 2e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int need = (m - row[i]) + (n - col[j]) - 1;
                if (mat[i][j] == '*')
                    need += 1;
                ans = min(ans, need);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}