#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

const int kMod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }

    if (n == 1 || m == 1) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'R') {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
        cout << 1 << endl;
        return 0;
    }

    if (mat[0][0] == 'R' || mat[n - 1][m - 1] == 'R') {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> far_right(n, vector<int>(m, -1)), far_down = far_right;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int now = (mat[i][j] == 'R');
            far_down[i][j] = far_right[i][j] = now;
            if (i + 1 < n) far_down[i][j] += far_down[i + 1][j];
            if (j + 1 < m) far_right[i][j] += far_right[i][j + 1];
        }
    }

    vector<vector<int>> dp_down(n, vector<int>(m, 0)), dp_right(dp_down);
    dp_down[n - 1][m - 1] = dp_right[n - 1][m - 1] = 1;
    vector<vector<int>> suff_down(n, vector<int>(m, 0)), suff_right(suff_down);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (j + 1 < m) {
                int last_right = m - 1 - far_right[i][j + 1];
                int ans = suff_down[i][j + 1];
                if (last_right + 1 < m)
                    ans -= suff_down[i][last_right + 1];
                dp_right[i][j] = ans % kMod;
            }
            if (i + 1 < n) {
                int last_down = n - 1 - far_down[i + 1][j];
                int ans = suff_right[i + 1][j];
                if (last_down + 1 < n)
                    ans -= suff_right[last_down + 1][j];
                dp_down[i][j] = ans % kMod;
                
            }
            suff_down[i][j] = dp_down[i][j];
            suff_right[i][j] = dp_right[i][j];
            if (i + 1 < n) suff_right[i][j] += suff_right[i + 1][j];
            if (j + 1 < m) suff_down[i][j] += suff_down[i][j + 1];
            suff_down[i][j] %= kMod;
            suff_right[i][j] %= kMod;
        }
    }

    int ans = dp_down[0][0] + dp_right[0][0];
    ans %= kMod;
    if (ans < 0) ans += kMod;
    cout << ans << endl;


    return 0;
}