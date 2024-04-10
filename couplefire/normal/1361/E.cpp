#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> g[100055], rg[100055];

int in_stack[100055];
vector<int> res;

bool bad[100055];
int d[100055];

int t;
int dfn[100055];

inline void add_edge(int from, int to) {
    g[from].push_back(to);
    rg[to].push_back(from);
}
bool dfs(int v) {
    in_stack[v] = 1;

    for (auto u: g[v]) {
        if (in_stack[u] == 2) {
            return false;
        }

        if (in_stack[u]) continue;

        if (!dfs(u)) {
            return false;
        }
    }

    in_stack[v] = 2;
    return true;
}

int depth[100055];
int low[100055];
vector<int> sta;

void rdfs(int v, int dep = 0) {
    in_stack[v] = 1;
    low[v] = depth[v] = dep;

    sta.push_back(v);
    vector<int> vec;

    for (auto u: g[v]) {
        if (in_stack[u] == 0) {
            rdfs(u, dep + 1);
            d[v] += d[u];
            low[v] = min(low[v], low[u]);
            vec.push_back(low[u]);
        } else {
            low[v] = min(low[v], depth[u]);
            vec.push_back(depth[u]);
        }
    }

    sort(vec.begin(), vec.end());

    if (vec.size() > 1 && vec[1] < depth[v]) {
        d[v]++;
        d[sta[vec[1]]]--;
    }

    sta.pop_back();
    in_stack[v] = 2;
}
void rrdfs(int v) {
    sta.push_back(v);
    in_stack[v] = 1;

    if (d[v] == 0 && d[sta[low[v]]] == 0) {
        res.push_back(v);
    } else {
        d[v] = 1;
    }

    for (auto u: g[v]) {
        if (in_stack[u]) continue;

        rrdfs(u);
    }

    sta.pop_back();
    in_stack[v] = 2;
}
int main() {
    mt19937 rng(19990520);
    int _t;
    cin >> _t;

    while (_t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            g[i].clear();
            rg[i].clear();
        }

        while (m--) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;

            add_edge(x, y);
        }

        res.clear();

        for (int t = 0; t < 100; t++) {
            ::t = 0;
            for (int i = 0; i < n; i++) {
                in_stack[i] = 0;
                bad[i] = false;
                d[i] = 0;
            }

            int v = uniform_int_distribution<int>(0, n - 1)(rng);

            if (!dfs(v)) {
                continue;
            }

            for (int i = 0; i < n; i++) in_stack[i] = 0;

            rdfs(v);

            for (int i = 0; i < n; i++) in_stack[i] = 0;

            rrdfs(v);

            break;
        }

        if (res.empty() || (int)res.size() * 5 < n) {
            puts("-1");
            continue;
        }

        sort(res.begin(), res.end());
        for (int v: res) printf("%d ", v + 1);
        puts("");
    }

    return 0;
}