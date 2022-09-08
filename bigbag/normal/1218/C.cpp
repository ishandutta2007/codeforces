#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

const int max_n = 505;
const long long inf = 1000111222000111222LL;
const int max_k = 500555;

int n, m, k, cost[max_k];
int l1[max_n][max_n], r1[max_n][max_n];
int l2[max_n][max_n], r2[max_n][max_n];
long long dp[max_n][max_n], s1[max_n][max_n], s2[max_n][max_n];
vector<pair<int, int>> all1[max_n][max_n], all2[max_n][max_n];
int cur;
pair<int, int> all[max_k];

void proc(vector<pair<int, int>> v[max_n][max_n], int l[max_n][max_n], int r[max_n][max_n]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            l[i][j] = cur;
            for (const auto &p : v[i][j]) {
                all[cur++] = p;
            }
            r[i][j] = cur;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i) {
        int x, y, d, t;
        scanf("%d%d%d%d%d", &x, &y, &d, &t, &cost[i]);
        const int sdx[] = {0, d, d, 0};
        const int sdy[] = {0, -d, 0, d};
        vector<pair<int, int>> v;
        for (int j = 0; j < 4; ++j) {
            int nx = x + sdx[j], ny = y + sdy[j];
            if ((t + j) % 4 == (nx + ny) % 4 && t <= nx + ny) {
                v.push_back({nx, ny});
            }
        }
        sort(v.begin(), v.end());
        if (v.size() == 1) {
            s1[v[0].first][v[0].second] += cost[i];
            s2[v[0].first][v[0].second] += cost[i];
        } else if (v.size() == 2) {
            if (v[0].first == v[1].first) {
                s1[v[0].first][v[0].second] += cost[i];
                all1[v[1].first][v[1].second].push_back({v[0].second, cost[i]});

                s2[v[0].first][v[0].second] += cost[i];
                s2[v[1].first][v[1].second] += cost[i];
            } else if (v[0].second == v[1].second) {
                s2[v[0].first][v[0].second] += cost[i];
                all2[v[1].first][v[1].second].push_back({v[0].first, cost[i]});

                s1[v[0].first][v[0].second] += cost[i];
                s1[v[1].first][v[1].second] += cost[i];
            } else {
                s1[v[0].first][v[0].second] += cost[i];
                s2[v[0].first][v[0].second] += cost[i];
                s1[v[1].first][v[1].second] += cost[i];
                s2[v[1].first][v[1].second] += cost[i];
            }
        }
    }
    proc(all1, l1, r1);
    proc(all2, l2, r2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long add = 0;
            for (int to = j + 1; to < m; ++to) {
                add += s1[i][to];
                for (int id = l1[i][to]; id < r1[i][to]; ++id) {
                    if (all[id].first < j) {
                        add += all[id].second;
                    }
                }
                dp[i][to] = min(dp[i][to], dp[i][j] + add);
            }
            add = 0;
            for (int to = i + 1; to < n; ++to) {
                add += s2[to][j];
                for (int id = l2[to][j]; id < r2[to][j]; ++id) {
                    if (all[id].first < i) {
                        add += all[id].second;
                    }
                }
                dp[to][j] = min(dp[to][j], dp[i][j] + add);
            }
        }
    }
    cout << dp[n - 1][m - 1] << "\n";
    return 0;
}