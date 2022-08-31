/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10;

struct SCC {
    int V, group_cnt;
    vector<vector<int> > adj, radj;
    vector<int> group_num, vis;
    stack<int> stk;

    // V = number of vertices
    SCC(int V): V(V), group_cnt(0), group_num(V), vis(V), adj(V), radj(V) {}

    // Call this to add an edge (0-based)
    void add_edge(int v1, int v2) {
        adj[v1].push_back(v2);
        radj[v2].push_back(v1);
    }

    void fill_forward(int x) {
        vis[x] = true;
        for (int i = 0; i < adj[x].size(); i++) {
            if (!vis[adj[x][i]]) {
                fill_forward(adj[x][i]);
            }
        }
        stk.push(x);
    }

    void fill_backward(int x) {
        vis[x] = false;
        group_num[x] = group_cnt;
        for (int i = 0; i < radj[x].size(); i++) {
            if (vis[radj[x][i]]) {
                fill_backward(radj[x][i]);
            }
        }
    }

    // Returns number of strongly connected components.
    // After this is called, group_num contains component assignments (0-based)
    int get_scc() {
        for (int i = 0; i < V; i++) {
            if (!vis[i]) fill_forward(i);
        }
        group_cnt = 0;
        while (!stk.empty()) {
            if (vis[stk.top()]) {
                fill_backward(stk.top());
                group_cnt++;
            }
            stk.pop();
        }
        return group_cnt;
    }
};

int sz[N], par[N];
vector<int> g[N];
bool ok[N];

int get_root(int u);
void merge(int u, int v);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			// par[i] = i;
			// sz[i] = 1;
			g[i].clear();
			ok[i] = true;
		}
		SCC scc(n);
		while (m--) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			scc.add_edge(a - 1, b - 1);
		}
		int k = scc.get_scc();
		if (k == 1) {
			cout << "No\n";
		} else {
			for (int u = 1; u <= n; ++u) {
				for (auto &v : g[u]) {
					if (scc.group_num[u - 1] != scc.group_num[v - 1]) {
						ok[scc.group_num[u - 1]] = false;
					}
				}
			}
			cout << "Yes\n";
			int x = 0;
			while (!ok[x]) {
				++x;
			}
			vector<int> v1, v2;
			for (int i = 1; i <= n; ++i) {
				if (scc.group_num[i - 1] == x) {
					v1.pb(i);
				} else {
					v2.pb(i);
				}
			}
			cout << v1.size() << ' ' << v2.size() << '\n';
			for (auto &i : v1) {
				cout << i << ' ';
			}
			cout << '\n';
			for (auto &i : v2) {
				cout << i << ' ';
			}
			cout << '\n';
		}
	}
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u != v) {
		sz[u] += sz[v];
		par[v] = u;
	}
}