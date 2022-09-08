/**
 *  created: 12/11/2021, 17:08:29
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, h[max_n];
vector<int> g[max_n], all[2];

void dfs(int v, int p) {
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        h[to] = h[v] ^ 1;
        dfs(to, v);
    }
}

void clr() {
    all[0].clear();
    all[1].clear();
    for (int i = 0; i < n; ++i) {
        g[i].clear();
        h[i] = 0;
    }
}

bool get_bit(int mask, int pos) {
    return (mask >> pos) & 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        if (2 * accumulate(h, h + n, 0) > n) {
            for (int i = 0; i < n; ++i) {
                h[i] ^= 1;
            }
        }
        const int c1 = accumulate(h, h + n, 0);
        for (int i = 1; i <= n; ++i) {
            int high = 31 - __builtin_clz(i);
            if (get_bit(c1, high)) {
                all[1].push_back(i);
            } else {
                all[0].push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << all[h[i]].back() << " ";
            all[h[i]].pop_back();
        }
        cout << "\n";
        clr();
    }
    return 0;
}