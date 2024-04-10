/**
 *  created: 11/07/2021, 18:26:53
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 502, inf = 1000111222;

const int max_v = 2 * max_n;
const int mod = 998244353;

int mul(int x, int y) {
    return 1LL * x * y % mod;
}

namespace matching {

const int max_n = max_v;

int n = -1;
vector<int> g[max_n];
int match[max_n], p[max_n], base[max_n], q[max_n];
bool used[max_n], blossom[max_n], used_lca[max_n];
int blocked = -1;

void init(int N) {
    blocked = -1;
    n = N;
    for (int i = 0; i < n; ++i) {
        g[i].clear();
    }
}

void add_edge(int u, int v) {
    assert(0 <= u && 0 <= v && u < n && v < n);
    if (u == v) {
        return;
    }
    g[u].push_back(v);
    g[v].push_back(u);
}

int lca(int a, int b) {
    memset(used_lca, 0, n);
    while (true) {
        a = base[a];
        used_lca[a] = true;
        if (match[a] == -1) {
            break;
        }
        a = p[match[a]];
    }
    while (true) {
        b = base[b];
        if (used_lca[b]) {
            return b;
        }
        b = p[match[b]];
    }
}

void mark_path(int v, int b, int children) {
    while (base[v] != b) {
        blossom[base[v]] = blossom[base[match[v]]] = true;
        p[v] = children;
        children = match[v];
        v = p[match[v]];
    }
}

int find_path(int root) {
    if (root == blocked) {
        return -1;
    }
    memset(used, 0, n);
    memset(p, -1, sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        base[i] = i;
    }
    used[root] = true;
    int qh = 0, qt = 0;
    q[qt++] = root;
    while (qh < qt) {
        int v = q[qh++];
        for (int to : g[v]) {
            if (base[v] == base[to] || match[v] == to || to == blocked) {
                continue;
            }
            if (to == root || match[to] != -1 && p[match[to]] != -1) {
                int curbase = lca(v, to);
                memset(blossom, 0, n);
                mark_path(v, curbase, to);
                mark_path(to, curbase, v);
                for (int i = 0; i < n; ++i) {
                    if (i != blocked && blossom[base[i]]) {
                        base[i] = curbase;
                        if (!used[i]) {
                            used[i] = true;
                            q[qt++] = i;
                        }
                    }
                }
            }
            else if (p[to] == -1) {
                p[to] = v;
                if (match[to] == -1) {
                    return to;
                }
                to = match[to];
                used[to] = true;
                q[qt++] = to;
            }
        }
    }
    return -1;
}

void greedy_init() {
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    random_shuffle(order.begin(), order.end());
    for (int i : order) {
        if (match[i] == -1 && i != blocked) {
            random_shuffle(g[i].begin(), g[i].end());
            for (int to : g[i]) {
                if (match[to] == -1 && to != blocked) {
                    match[to] = i;
                    match[i] = to;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }
}

vector<pair<int, int>> find_matching() {
    if (n < 0) {
        cerr << "You should call init() first" << endl;
        assert(false);
    }
    memset(match, -1, sizeof(int) * n);
    greedy_init();
    for (int i = 0; i < n; ++i) {
		if (match[i] == -1) {
			int v = find_path(i);
			while (v != -1) {
				int pv = p[v], ppv = match[pv];
				match[v] = pv;
				match[pv] = v;
				v = ppv;
			}
		}
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        if (match[i] != -1 && i < match[i]) {
            res.push_back({i, match[i]});
        }
    }
    return res;
}

}

int t, n, a[max_v][max_n], pr[max_v];
bool taken[max_v], used[max_v];
vector<int> g[max_v], path;

void clr() {
    for (int i = 0; i < max_v; ++i) {
        g[i].clear();
        taken[i] = used[i] = 0;
    }
}

bool dfs(int v) {
    used[v] = 1;
    path.push_back(v);
    for (int to : g[v]) {
        const int need = pr[to];
        if (used[to]) {
            return false;
        }
        if (used[need]) {
            continue;
        }
        if (!dfs(need)) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", &a[i][j]);
                --a[i][j];
            }
        }
        clr();
        matching::init(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = i + 1; j < 2 * n; ++j) {
                bool bad = false;
                for (int k = 0; k < n; ++k) {
                    bad |= a[i][k] == a[j][k];
                }
                if (bad) {
                    matching::add_edge(i, j);
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        auto v = matching::find_matching();
        for (auto p : v) {
            //cout << p.first << " " << p.second << endl;
            pr[p.first] = p.second;
            pr[p.second] = p.first;
        }
        int ans = 1;
        vector<int> ids;
        for (int i = 0; i < 2 * n; ++i) {
            if (taken[i]) {
                continue;
            }
            memset(used, 0, sizeof(used));
            path.clear();
            if (dfs(i)) {
                for (int v : path) {
                    ids.push_back(v);
                    taken[v] = taken[pr[v]] = 1;
                }
                memset(used, 0, sizeof(used));
                path.clear();
                if (dfs(pr[i])) {
                    ans = mul(ans, 2);
                }
            } else {
                memset(used, 0, sizeof(used));
                path.clear();
                assert(dfs(pr[i]));
                for (int v : path) {
                    taken[v] = taken[pr[v]] = 1;
                    ids.push_back(v);
                }
            }
        }
        sort(ids.begin(), ids.end());
        ids.erase(unique(ids.begin(), ids.end()), ids.end());
        printf("%d\n", ans);
        for (int v : ids) {
            printf("%d ", v + 1);
        }
        puts("");
    }
    return 0;
}