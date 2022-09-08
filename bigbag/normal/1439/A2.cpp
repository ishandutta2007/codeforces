#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int t, n, m, f[max_n][max_n];
string s;
vector<vector<pair<int, int>>> ans;

void op(int x1, int y1, int x2, int y2, int x3, int y3) {
    ans.push_back({{x1, y1}, {x2, y2}, {x3, y3}});
    f[x1][y1] ^= 1;
    f[x2][y2] ^= 1;
    f[x3][y3] ^= 1;
}

const int seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 generator(seed);

int rnd() {
    return generator() >> 1;
}

int rnd(int r) {
    return rnd() % r;
}

int rnd(int l, int r) {
    return l + rnd(r - l + 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        if (0) {
            n = rnd(2, 4);
            m = rnd(2, 4);
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    f[i][j] = rnd(2);
                    cout << f[i][j];
                }
                cout << endl;
            }
            cout << endl;
        } else {
            cin >> n >> m;
            for (int i = 0; i < n; ++i) {
                cin >> s;
                for (int j = 0; j < m; ++j) {
                    f[i][j] = s[j] - '0';
                }
            }
        }
        ans.clear();
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j + 2 < m; ++j) {
                if (f[i][j]) {
                    op(i, j, i + 1, j, i, j + 1);
                }
            }
            if (f[i][m - 2] && f[i][m - 1]) {
                op(i, m - 2, i, m - 1, i + 1, m - 1);
            } else if (f[i][m - 2]) {
                op(i, m - 2, i + 1, m - 2, i + 1, m - 1);
            } else if (f[i][m - 1]) {
                op(i, m - 1, i + 1, m - 2, i + 1, m - 1);
            }
        }
        //cout << f[n - 1][0] << f[n - 1][1] << f[n - 1][2] << endl;
        for (int i = 0; i + 2 < m; ++i) {
            if (f[n - 1][i] && f[n - 1][i + 1]) {
                if (i + 3 == m && f[n - 1][i + 1] && f[n - 1][i + 2]) {
                    op(n - 1, i, n - 1, i + 1, n - 2, m - 2);
                    op(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
                    op(n - 1, m - 2, n - 2, m - 2, n - 2, m - 1);
                    break;
                }
                op(n - 2, i, n - 2, i + 1, n - 1, i);
                op(n - 2, i, n - 2, i + 1, n - 1, i + 1);
                ++i;
            } else if (f[n - 1][i]) {
                if (i + 3 == m && !f[n - 1][i + 1] && !f[n - 1][i + 2]) {
                    op(n - 1, i, n - 1, i + 1, n - 2, i + 1);
                    op(n - 1, m - 1, n - 2, m - 1, n - 1, m - 2);
                    op(n - 1, m - 1, n - 2, m - 1, n - 2, m - 2);
                    break;
                }
                op(n - 1, i, n - 1, i + 1, n - 2, i + 1);
                op(n - 1, i + 2, n - 1, i + 1, n - 2, i + 1);
                ++i;
            }
        }
        vector<int> ids;
        if (f[n - 1][m - 2]) {
            ids.push_back(m - 2);
        }
        if (f[n - 1][m - 1]) {
            ids.push_back(m - 1);
        }
        if (ids.size() == 2) {
            op(n - 1, m - 2, n - 2, m - 2, n - 2, m - 1);
            op(n - 1, m - 1, n - 2, m - 2, n - 2, m - 1);
        } else if (ids.size() == 1) {
            op(n - 1, ids[0], n - 2, m - 2, n - 2, m - 1);
            op(n - 1, m - 2, n - 1, m - 1, n - 2, m - 1);
            op(n - 1, m - 2, n - 1, m - 1, n - 2, m - 2);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                assert(!f[i][j]);
            }
        }
        assert(ans.size() <= n * m);
        cout << ans.size() << "\n";
        for (auto p : ans) {
            for (auto res : p) {
                cout << res.first + 1 << " " << res.second + 1 << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}