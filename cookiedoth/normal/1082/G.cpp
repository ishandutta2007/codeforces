/*

Code for problem G by savkinsd2089
Generated 29 Nov 2018 at 05.27 pm
The Moon is Waning Gibbous (55% of Full)










(@)(@)(@)(@)(@)

z_z
z_z
o_O

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define int long long
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

namespace Dinic {
    const ll INF = 1e18;
    const int lg = 60;

    struct edge {
        int u, v;
        ll cap, flow;

        edge() : u(-1), v(-1), cap(0), flow(0) {}

        edge(int _u, int _v, ll _cap, ll _flow) : u(_u), v(_v), cap(_cap), flow(_flow) {}
    };

    vector<edge> e;
    vector<vector<int> > g;
    vector<int> first;
    vector<ll> dist;
    int ptr = 0;

    void init(int n) {
        g.resize(n);
    }

    void add_edge(int u, int v, ll cap) {
        e.emplace_back(u, v, cap, 0); // straight edge
        g[u].push_back(ptr++);
        e.emplace_back(v, u, 0, 0); // back edge, cap for an undirected graph
        g[v].push_back(ptr++);
    }

    bool bfs(int s, int t, ll c) {
        dist.assign(g.size(), INF);
        first.assign(g.size(), 0);
        vector<int> q;
        q.push_back(s);
        dist[s] = 0;
        for (int i = 0; i < (int) q.size(); i++) {
            int u = q[i];
            for (int ind : g[u]) {
                int v = e[ind].v, cap = e[ind].cap, flow = e[ind].flow;
                if (cap - flow >= c && dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push_back(v);
                }
            }
        }
        return dist[t] != INF;
    }

    ll dfs(int u, int t, ll c, ll cur) {
        if (u == t) {
            return cur;
        }
        for (; first[u] < (int) g[u].size(); first[u]++) {
            int ind = g[u][first[u]];
            int v = e[ind].v, cap = e[ind].cap, flow = e[ind].flow;
            if (cap - flow >= c && dist[v] == dist[u] + 1) {
                ll d = dfs(v, t, c, min(cur, cap - flow));
                if (d > 0) {
                    e[ind].flow += d;
                    e[ind ^ 1].flow -= d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        dist.assign(g.size(), INF), first.assign(g.size(), 0);
        for (ll c = (1LL << lg); c > 0; c >>= 1) {
            while (bfs(s, t, c)) {
                while (dfs(s, t, c, INF));
            }
        }
        ll flow = 0;
        for (int ind : g[s]) {
            flow += e[ind].flow;
        }
        return flow;
    }
}

int n, m;
ll w, ans;

signed main() {
	cin >> n >> m;
	Dinic::init(n + m + 2);
	for (int i = 0; i < n; ++i) {
		cin >> w;
		Dinic::add_edge(n + m, i, w);
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v >> w;
		u--;
		v--;
		Dinic::add_edge(u, n + i, Dinic::INF);
		Dinic::add_edge(v, n + i, Dinic::INF);
		Dinic::add_edge(n + i, n + m + 1, w);
		ans += w;
	}
	ans -= Dinic::max_flow(n + m, n + m + 1);
	cout << ans << endl;
}