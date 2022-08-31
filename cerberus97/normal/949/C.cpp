/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

vector<int> g[N], group_elems[N];
vector<pii> edges;
int ctr[N], u[N];

struct SCC {
    int V, group_cnt;
    vector<vector<int> > adj, radj;
    vector<int> group_num, vis;
    stack<int> stk;

    // V = number of vertices
    SCC(int V): V(V), group_cnt(0), group_num(V), vis(V), adj(V), radj(V) {}

    // Call this to add an edge (0-based)
    void add_edge(int v1, int v2) {
    	edges.pb({v1, v2});
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

int main() {
	int n, m, h;
	cin >> n >> m >> h;
	for (int i = 0; i < n; ++i) {
		cin >> u[i];
	}
	SCC scc(n);
	while (m--) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		if ((u[x] + 1) % h == u[y]) {
			scc.add_edge(x, y);
		}
		if ((u[y] + 1) % h == u[x]) {
			scc.add_edge(y, x);
		}
	}
	int k = scc.get_scc();
	for (auto &e : edges) {
		int x = scc.group_num[e.first];
		int y = scc.group_num[e.second];
		if (x != y) {
			g[x].pb(y);
		}
	}
	int best = n + 5, best_group = -1;
	for (int i = 0; i < n; ++i) {
		ctr[scc.group_num[i]]++;
		group_elems[scc.group_num[i]].pb(i);
	}
	for (int i = 0; i < k; ++i) {
		if (g[i].empty() and ctr[i] < best) {
			best = ctr[i];
			best_group = i;
		}
	}
	cout << best << endl;
	for (auto &i : group_elems[best_group]) {
		cout << i + 1 << ' ';
	}
}