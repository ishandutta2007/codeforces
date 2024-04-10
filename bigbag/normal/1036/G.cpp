#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;
const int max_s = 22;

int n, m, in[max_n], out[max_n], source_num[max_n], sink_num[max_n];
char used[max_n];
vector<int> g[max_n], sources, sinks;
bitset<max_s> can[max_s];

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

bool get_bit(int mask, int pos) {
    return (bool) (mask & (1 << pos));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        ++out[u];
        ++in[v];
    }
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0) {
            sources.push_back(i);
        }
        if (out[i] == 0) {
            sinks.push_back(i);
        }
    }
    for (int i = 0; i < sources.size(); ++i) {
        memset(used, 0, sizeof(used));
        dfs(sources[i]);
        for (int j = 0; j < sinks.size(); ++j) {
            if (used[sinks[j]]) {
                can[i][j] = 1;
            }
        }
    }
    for (int mask = 1; mask + 1 < (1 << sources.size()); ++mask) {
        bitset<max_s> ok;
        int cnt = 0;
        for (int i = 0; i < sources.size(); ++i) {
            if (get_bit(mask, i)) {
                ok |= can[i];
                ++cnt;
            }
        }
        if (cnt >= ok.count()) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}