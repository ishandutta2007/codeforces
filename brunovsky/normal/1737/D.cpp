#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int64_t w[501][501];
int dist[501][501];

constexpr int dinf = 1e7;
constexpr int64_t winf = 4e15;

template <typename T>
void setmin(T& a, T b) {
    a = min(a, b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> dist(N, vector<int>(N, dinf));
        vector<tuple<int, int, int64_t>> edges;

        for (int i = 0; i < M; i++) {
            int u, v;
            int64_t w;
            cin >> u >> v >> w, u--, v--;
            dist[u][v] = dist[v][u] = 1;
            edges.emplace_back(u, v, w);
            edges.emplace_back(v, u, w);
        }
        for (int u = 0; u < N; u++) {
            dist[u][u] = 0;
        }
        for (int k = 0; k < N; k++) {
            for (int u = 0; u < N; u++) {
                for (int v = 0; v < N; v++) {
                    setmin(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }

        const int s = 0, t = N - 1;
        int64_t ans = winf;
        for (int c = 0; c < N; c++) {
            for (auto [u, v, w] : edges) {
                int d = dist[c][u] + 2 + dist[s][c] + dist[t][c];
                setmin(ans, w * d);
            }
        }
        for (auto [u, v, w] : edges) {
            int d = dist[s][u] + 1 + dist[t][v];
            setmin(ans, w * d);
        }
        cout << ans << '\n';
    }
    return 0;
}