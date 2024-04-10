#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            cin >> grid[i];
        }

        constexpr char CACT = '#';
        constexpr int inf = 1e9;
        constexpr int dd[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        constexpr int dp[4][2] = {{-1, -1}, {+1, +1}, {+1, -1}, {-1, +1}};

        auto fine = [&](int x, int y) { return (0 <= x && x < N && 0 <= y && y < M); };

        auto can = [&](int r, int c) {
            if (grid[r][c] == '#') {
                return 0;
            }
            for (auto [dr, dc] : dd) {
                int x = r + dr, y = c + dc;
                if (fine(x, y) && grid[x][y] == CACT) {
                    return -1;
                }
            }
            return 1;
        };

        vector<vector<int>> cost(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cost[i][j] = can(i, j);
            }
        }

        using pos = pair<int, int>;

        auto run = [&](bool left) {
            vector<vector<int>> dist(N, vector<int>(M, inf));
            vector<vector<pos>> prev(N, vector<pos>(M, {-1, -1}));

            queue<pair<int, int>> Q[2];
            int s = left ? 0 : M - 1;
            int d = 0;

            for (int i = 0; i < N; i++) {
                if (cost[i][s] != -1) {
                    Q[cost[i][s]].push({i, s});
                    dist[i][s] = cost[i][s];
                }
            }

            while (Q[0].size() + Q[1].size()) {
                while (Q[0].size()) {
                    auto [r, c] = Q[0].front();
                    Q[0].pop();

                    for (auto [dr, dc] : dp) {
                        int x = r + dr, y = c + dc;
                        if (fine(x, y) && dist[x][y] == inf && cost[x][y] != -1) {
                            Q[cost[x][y]].push({x, y});
                            dist[x][y] = cost[x][y] + d;
                            prev[x][y] = {r, c};
                        }
                    }
                }

                swap(Q[0], Q[1]), d++;
            }

            return make_pair(move(dist), move(prev));
        };

        auto [ldist, lprev] = run(0);
        auto [rdist, rprev] = run(1);
        auto ans = make_pair(inf, make_pair(-1, -1));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                auto c = ldist[i][j] + rdist[i][j] - cost[i][j];
                auto p = make_pair(c, make_pair(i, j));
                ans = min(ans, p);
            }
        }

        debug(ans);

        if (ans.first == inf) {
            cout << "NO\n";
            continue;
        }

        auto [r, c] = ans.second;
        grid[r][c] = CACT;

        {
            int x = r, y = c;
            while (lprev[x][y].first != -1) {
                tie(x, y) = lprev[x][y];
                grid[x][y] = CACT;
            }
        }
        {
            int x = r, y = c;
            while (rprev[x][y].first != -1) {
                tie(x, y) = rprev[x][y];
                grid[x][y] = CACT;
            }
        }

        cout << "YES\n";
        for (int i = 0; i < N; i++) {
            cout << grid[i] << '\n';
        }
    }
    // If it works its a path on consistent parity obviously
    // It can zigzag arbitrary but always 45 connected
    // Run two 0-1 bfs, one from left side one from right side
    // Some spots might be unreachable
    return 0;
}