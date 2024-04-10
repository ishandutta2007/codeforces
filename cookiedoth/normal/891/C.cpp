#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

struct edge {
    int u, v, cost, num, u1, v1;
    edge(int _u, int _v, int _cost, int _num): u(_u), v(_v), cost(_cost), num(_num), u1(0), v1(0) {}
};

bool operator < (edge a, edge b) {
    return a.cost < b.cost;
}

struct dsu {
	vector<int> p, rnk;
	int n;
	dsu() {}
	void init(int _n) {
		n = _n;
		p.resize(n);
		rnk.resize(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}
	int find_root(int v) {
		if (v == p[v])
			return v;
		int root = find_root(p[v]);
		p[v] = root;
		return root;
	}
	void join(int u, int v) {
		u = find_root(u);
		v = find_root(v);
		if (u == v)
			return;
		if (rnk[u] < rnk[v])
			p[u] = v;
		if (rnk[v] < rnk[u])
			p[v] = u;
		if (rnk[u] == rnk[v]) {
			p[u] = v;
			rnk[v]++;
		}
	}
	bool cmp(int u, int v) {
		return find_root(u) == find_root(v);
	}
};

const int mx = 1000000;
int n, m, q, used[mx], p[mx];
vector<edge> e, eq;
dsu T;
vector<int> g[mx];

int dfs(int v, int pv, int color) {
    int res = 1;
    used[v] = color;
    for (auto v1 : g[v]) {
        if (v1 != pv) {
            if (used[v1] == color)
                return 0;
            else
                res = min(res, dfs(v1, v, color));
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        u--;
        v--;
        e.push_back({u, v, cost, i});
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < m; ++i) {
        p[e[i].num] = i;
    }
    T.init(n);
    int ptr = 0;
    for (int i = 0; i < m; ++i) {
        if (i > 0 && e[i].cost != e[i - 1].cost) {
            for (int j = ptr; j < i; ++j) {
                T.join(T.find_root(e[j].u), T.find_root(e[j].v));
            }
            ptr = i;
        }
        int u = e[i].u, v = e[i].v;
        int c1 = T.find_root(u), c2 = T.find_root(v);
        e[i].u1 = c1;
        e[i].v1 = c2;
    }
    for (int j = ptr; j < m; ++j) {
        T.join(T.find_root(e[j].u), T.find_root(e[j].v));
    }
    cin >> q;
    int dfs_color = 0;
    for (int i = 0; i < q; ++i) {
        int k;
        eq.clear();
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int num;
            cin >> num;
            num--;
            num = p[num];
            eq.push_back(e[num]);
        }
        sort(eq.begin(), eq.end());
        int ptr = 0, good = 1;
        for (int j = 1; j <= k; ++j) {
            if (j == k || eq[j].cost != eq[j - 1].cost) {
                int start_dfs = dfs_color;
                vector<int> undo;
                for (int x = ptr; x < j; ++x) {
                    g[eq[x].u1].push_back(eq[x].v1);
                    g[eq[x].v1].push_back(eq[x].u1);
                    undo.push_back(eq[x].u1);
                    undo.push_back(eq[x].v1);
                }
                for (auto v : undo) {
                    if (used[v] <= start_dfs) {
                        dfs_color++;
                        good = min(good, dfs(v, -1, dfs_color));
                    }
                }
                for (auto v : undo) {
                    g[v].clear();
                }
                ptr = j;
            }
        }
        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}