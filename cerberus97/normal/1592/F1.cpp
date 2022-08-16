#include <bits/stdc++.h>

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    fast_cin();
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        string inp; cin >> inp;
        for (int j = 0; j < m; ++j) {
            a[i][j] = (inp[j] == 'B');
        }
    }
    auto bak = a;
    for (int j = 0; j < m; ++j) {
        int cur = 0;
        for (int i = n - 1; i >= 0; --i) {
            a[i][j] = (a[i][j] != cur);
            cur = bak[i][j];
        }
    }
    int base_cost = 0;
    vector<vector<int>> costs(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = a[i][j], y = a[i][j + 1], cost = (x != y);
            base_cost += cost;
            if (i == n - 1 and j == m - 1) {
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < m; ++y) {
                        costs[x][y] += (1 - 2 * cost);
                    }
                }
            } else if (i == n - 1) {
                for (int h = 0; h < n; ++h) {
                    costs[h][j + 1] += (1 - 2 * cost);
                }
            } else if (j == m - 1) {
                for (int x = 0; x < m; ++x) {
                    costs[i + 1][x] += (1 - 2 * cost);
                }
            } else {
                costs[i + 1][j + 1] += (1 - 2 * cost);
            }
        }
    }
    int ans = 4 * n * m;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cand = base_cost + costs[i][j] + ((i == n) ? 0 : 3);
            // cout << i << ' ' << j << ' ' << cand << endl;
            ans = min(ans, cand);
        }
    }
    cout << ans << '\n';
}