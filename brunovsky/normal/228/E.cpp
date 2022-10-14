#include <bits/stdc++.h>

using namespace std;

#define long int64_t
#define DV(a) (" [" #a "=" + to_string(a) + "]")

// *****

struct twosat_scc {
    int N, C = 0; // N is the number of variables
    vector<unordered_set<int>> adj;
    vector<int> assignment, cmap;

    twosat_scc(int N = 0) : N(N), adj(2 * N) {}

    int add_var() { return adj.resize(2 * N + 2), N++; }

    void either(int u, int v) {
        u = u < 0 ? 2 * ~u : 2 * u + 1; // remove these lines if you want to input
        v = v < 0 ? 2 * ~v : 2 * v + 1; // 2u and 2u+1 directly, with 2n being negated
        assert(0 <= u && u < 2 * N && 0 <= v && v < 2 * N);
        adj[u ^ 1].insert(v);
        adj[v ^ 1].insert(u);
    }

    void set(int u) { either(u, u); }

    vector<int> index, lowlink;
    vector<bool> onstack;
    stack<int> S;
    int depth;

    void tarjan(int u) {
        index[u] = lowlink[u] = depth++;
        S.push(u), onstack[u] = true;

        for (int v : adj[u]) {
            if (!index[v]) {
                tarjan(v);
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
        S = stack<int>();
        depth = 1, C = 0;

        for (int u = 0; u < 2 * N; u++) {
            if (!index[u]) {
                tarjan(u);
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

auto solve() {
    int N, M;
    cin >> N >> M;
    twosat_scc sat(N); // 1=>we visit, 0=>we don't visit
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        if (c) {
            sat.either(a, ~b);
            sat.either(~a, b);
        } else {
            sat.either(a, b);
            sat.either(~a, ~b);
        }
    }
    if (!sat.solve()) {
        cout << "Impossible" << endl;
    } else {
        int x = 0;
        for (int u = 0; u < N; u++) {
            x += sat.assignment[u];
        }
        int flip = x > N - x ? 0 : 1;
        int many = min(x, N - x);
        cout << many << endl;
        for (int u = 0; u < N; u++) {
            if (sat.assignment[u] == flip) {
                cout << u + 1 << ' ';
            }
        }
        if (many > 0) {
            cout << endl;
        }
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}