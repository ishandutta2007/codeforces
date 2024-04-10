#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

struct maximum_matching {
    int U, V;
    vector<set<int>> adj, rev;
    vector<int> mu, mv;

    maximum_matching(int U, int V) : U(U), V(V), adj(U), rev(V) {}

    void add(int u, int v) {
        assert(0 <= u && u < U && 0 <= v && v < V);
        adj[u].insert(v);
        rev[v].insert(u);
    }

    void u_clear(int u) {
        for (int v : adj[u])
            rev[v].erase(u);
        adj[u].clear();
    }
    void v_clear(int v) {
        for (int u : rev[v])
            adj[u].erase(v);
        rev[v].clear();
    }

    vector<int> vis;
    int iteration;
    static inline constexpr int inf = INT_MAX / 2;

    bool dfs(int u) {
        vis[u] = iteration;
        for (int v : adj[u]) {
            if (mv[v] == -1) {
                mu[u] = v, mv[v] = u;
                return true;
            }
        }
        for (int v : adj[u]) {
            if (vis[mv[v]] != iteration && dfs(mv[v])) {
                mu[u] = v, mv[v] = u;
                return true;
            }
        }
        return false;
    }

    int compute() {
        vis.assign(U, 0);
        mu.assign(U, -1);
        mv.assign(V, -1);
        iteration = 0;
        int new_matchings = 0, matchings = 0;
        do {
            iteration++, new_matchings = 0;
            for (int u = 0; u < U; u++) {
                if (mu[u] == -1 && dfs(u)) {
                    new_matchings++;
                }
            }
            matchings += new_matchings;
        } while (new_matchings);
        return matchings;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, E, K;
    cin >> N >> E >> K;

    maximum_matching mm(N + 1, N + 1);
    vector<array<int, 2>> edges(E);
    vector<set<int>> in(N + 1), out(N + 1);
    for (auto& [u, v] : edges) {
        cin >> u >> v;
        mm.add(u, v);
        out[u].insert(v);
        in[v].insert(u);
    }

    int U = mm.compute();
    assert(U < N);
    // N - U goblins are needed to raid the entire graph
    // to survive N - 1 goblins we need U upgrades

    vector<pair<int, bool>> upgrades;
    vector<bool> u_alive(N + 1, true), v_alive(N + 1, true);
    int Z = 0;
    while (Z < U) {
        for (int u = 1; u <= N && Z < U; u++) {
            if (u_alive[u]) {
                mm.u_clear(u);
                int m = mm.compute();
                if (m < U - Z) {
                    u_alive[u] = false;
                    upgrades.push_back({u, false});
                    Z++;
                    for (int v : out[u]) {
                        in[v].erase(u);
                    }
                } else {
                    for (int v : out[u]) {
                        mm.add(u, v);
                    }
                }
            }
        }
        for (int v = 1; v <= N && Z < U; v++) {
            if (v_alive[v]) {
                mm.v_clear(v);
                int m = mm.compute();
                if (m < U - Z) {
                    v_alive[v] = false;
                    upgrades.push_back({v, true});
                    Z++;
                    for (int u : in[v]) {
                        out[u].erase(v);
                    }
                } else {
                    for (int u : in[v]) {
                        mm.add(u, v);
                    }
                }
            }
        }
    }

    vector<long> x(K + 1), y(K + 1);
    for (int i = 1; i <= K; i++) {
        cin >> x[i] >> y[i];
    }
    // how many upgrades do we need to survive k goblins
    vector<int> survive(N + 1);
    for (int n = 1; n <= N; n++) {
        survive[n] = max(0, U - (N - n - 1));
    }
    // how many upgrades we need in total, to survive the last wave
    int S = survive[K];

    vector<vector<long>> dp(K + 1, vector<long>(S + 1));
    for (int k = survive[1]; k <= S; k++) {
        dp[1][k] = max(long(0), x[1] - k * y[1]);
    }
    for (int i = 2; i <= K; i++) {
        for (int k = survive[i]; k <= S; k++) {
            for (int j = survive[i - 1]; j <= k; j++) {
                long gain = max(long(0), x[i] - (k - j) * y[i]);
                dp[i][k] = max(dp[i][k], dp[i - 1][j] + gain);
            }
        }
    }

    // reconstruct the answer
    vector<int> amount(K + 1);
    int s = S;
    for (int i = K; i >= 2; i--) {
        for (int j = s; j >= 0; j--) {
            long gain = max(long(0), x[i] - (s - j) * y[i]);
            if (dp[i][s] == dp[i - 1][j] + gain) {
                amount[i] = s - j;
                s = j;
                break;
            }
            assert(j > 0);
        }
    }
    amount[1] = s;

    s = 0;
    cout << K + S << endl;
    for (int i = 1; i <= K; i++) {
        for (int a = 0; a < amount[i]; a++, s++) {
            auto [u, right] = upgrades[s];
            cout << (right ? -u : u) << " ";
        }
        cout << 0 << " ";
    }

    cout << endl;
    return 0;
}