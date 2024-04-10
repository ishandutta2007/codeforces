#include <bits/stdc++.h>

using namespace std;

#define long int64_t

int main() {
    ios::sync_with_stdio(false);
    int Q, a0, c0;
    cin >> Q >> a0 >> c0;
    int N = Q + 1; // one query second type
    int D = 1 + 8 * sizeof(N) - __builtin_clz(N - 1);

    vector<int> depth(N + 1);
    vector<vector<int>> up(D, vector<int>(N + 1, 0));
    vector<int> gold(N + 1), cost(N + 1);
    depth[0] = -1;
    depth[1] = 0;
    gold[1] = a0;
    cost[1] = c0;

    auto add_node = [&](int u, int p) {
        up[0][u] = p;
        for (int b = 1; b < D; b++) {
            if (up[b - 1][u] != 0) {
                up[b][u] = up[b - 1][up[b - 1][u]];
            }
        }
    };

    auto get_ancestor = [&](int u, int steps) { // O(log N)
        for (int b = D - 1; b >= 0; b--) {
            if (steps & 1 << b) {
                u = up[b][u];
            }
        }
        return u;
    };

    auto get_positive = [&](int u) { // O(log N)
        for (int b = D - 1; b >= 0; b--) {
            if (gold[up[b][u]] > 0) {
                u = up[b][u];
            }
        }
        return u;
    };

    int next_node = 1;
    while (Q--) {
        int type;
        cin >> type;
        next_node++;
        if (type == 1) {
            int p, a, c;
            cin >> p >> a >> c, p++;
            int u = next_node;
            gold[u] = a;
            cost[u] = c;
            depth[u] = depth[p] + 1;
            add_node(u, p);
        } else {
            int u, want;
            cin >> u >> want, u++;
            int v = get_positive(u);

            int took = 0;
            long spent = 0;
            while (v != u && took < want) {
                int take = min(want - took, gold[v]);
                gold[v] -= take;
                took += take;
                spent += 1LL * take * cost[v];
                v = get_ancestor(u, depth[u] - depth[v] - 1);
            }
            if (took < want) {
                assert(u == v);
                int take = min(want - took, gold[v]);
                gold[v] -= take;
                took += take;
                spent += 1LL * take * cost[v];
            }
            cout << took << ' ' << spent << endl;
        }
    }

    return 0;
}