#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

struct twosat_scc {
    int N, C = 0; // N is the number of variables
    vector<array<int, 2>> g;
    vector<int> off, assignment, cmap;

    explicit twosat_scc(int N = 0) : N(N) {}

    int add_var() { return N++; }

    void either(int u, int v) {
        u = u < 0 ? 2 * ~u : 2 * u + 1; // remove these lines if you want to input
        v = v < 0 ? 2 * ~v : 2 * v + 1; // 2u and 2u+1 directly, with 2n+1 true, 2n false
        assert(0 <= u && u < 2 * N && 0 <= v && v < 2 * N);
        g.push_back({u ^ 1, v});
        g.push_back({v ^ 1, u});
    }

    void equal(int u, int v) { either(u, ~v), either(~u, v); }

    void opposite(int u, int v) { either(u, v), either(~u, ~v); }

    void at_most_one(const vector<int>& vars) {
        int V = vars.size();
        if (V <= 1) {
            return;
        }
        int cur = ~vars[0];
        for (int i = 2; i < V; i++) {
            int next = add_var();
            either(cur, ~vars[i]);
            either(cur, next);
            either(~vars[i], next);
            cur = ~next;
        }
        either(cur, ~vars[1]);
    }

    void set(int u) { either(u, u); }

    vector<int> index, lowlink;
    vector<bool> onstack;
    stack<int> S;
    int depth;

    void dfs(int u) {
        index[u] = lowlink[u] = depth++;
        S.push(u), onstack[u] = true;

        for (int e = off[u]; e < off[u + 1]; e++) {
            int v = g[e][1];
            if (!index[v]) {
                dfs(v);
                lowlink[u] = min(lowlink[u], lowlink[v]);
            } else if (onstack[v]) {
                lowlink[u] = min(lowlink[u], index[v]);
            }
        }

        if (index[u] == lowlink[u]) {
            int v, c = C++;
            do {
                v = S.top(), S.pop(), onstack[v] = false;
                cmap[v] = c;
                if (assignment[v >> 1] == -1)
                    assignment[v >> 1] = v & 1;
            } while (u != v);
        }
    }

    bool solve() {
        assignment.assign(N, -1);
        cmap.assign(2 * N, 0);
        index.assign(2 * N, 0);
        lowlink.assign(2 * N, 0);
        onstack.assign(2 * N, false);
        off.assign(2 * N + 1, 0);
        S = stack<int>();
        depth = 1, C = 0;

        sort(begin(g), end(g));

        for (auto [u, v] : g) {
            off[u + 1]++;
        }
        for (int u = 1; u <= 2 * N; u++) {
            off[u] += off[u - 1];
        }

        for (int u = 0; u < 2 * N; u++) {
            if (!index[u]) {
                dfs(u);
            }
        }
        for (int u = 0; u < N; u++) {
            assert(assignment[u] >= 0);
            if (cmap[2 * u] == cmap[2 * u + 1]) {
                return false;
            }
        }
        return true;
    }
};

#define marked(i, j)   (grid[i][j] == 'X')
#define unmarked(i, j) (grid[i][j] != 'X')

constexpr int dd[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    twosat_scc sat(N * M);
    auto id = [&](int i, int j) { return i * M + j; };
    bool busted = false;

    for (int i = 1; i + 1 < N && !busted; i++) {
        for (int j = 1; j + 1 < M && !busted; j++) {
            if (grid[i][j] == 'X') {
                vector<int> adj;
                for (auto [dx, dy] : dd) {
                    if (unmarked(i + dx, j + dy)) {
                        adj.push_back(id(i + dx, j + dy));
                    }
                }
                int A = adj.size();
                if (A % 2 != 0) {
                    busted = true;
                    break;
                }
                if (A == 2) {
                    sat.opposite(adj[0], adj[1]);
                } else if (A == 4) {
                    sat.opposite(adj[0], adj[2]);
                    sat.opposite(adj[1], adj[3]);
                }
            }
        }
    }

    if (busted || !sat.solve()) {
        cout << "NO\n";
    } else {
        vector<vector<int>> ans(N, vector<int>(M, 0));
        cout << "YES\n";

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (unmarked(i, j)) {
                    if (sat.assignment[id(i, j)]) {
                        ans[i][j] = 4;
                    } else {
                        ans[i][j] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (marked(i, j)) {
                    for (auto [dx, dy] : dd) {
                        if (unmarked(i + dx, j + dy)) {
                            ans[i][j] += ans[i + dx][j + dy];
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << ans[i][j] << " \n"[j + 1 == M];
            }
        }
    }

    return 0;
}