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
typedef long long LL;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;


/* Dinic's courtesy Brian Bi */
struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  vector<bool> mark;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N), mark(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }

  void find_cut(int s) {
  	if (mark[s]) {
  		return;
  	}
  	mark[s] = true;
  	for (int e_id : g[s]) {
  		Edge e = E[e_id];
  		if (e.flow < e.cap) {
  			find_cut(e.v);
  		}
  	}
  }
};

const int N = 1e3 + 10, M = 2e6 + 10, inf = 1e8;

struct pt {
	int x, y;
	bool operator<(const pt &o) const {
		return tie(x, y) < tie(o.x, o.y);
	}
};

struct segment {
	int x1, y1, x2, y2;
};

pt p[N];
map<int, int> mpx, mpy;
vector<int> x_pts[N], y_pts[N];
vector<int> brk_x[N], brk_y[N];
vector<segment> hz_segments, vt_segments;
int revx[N], revy[N];

bool in_range(int x, int x1, int x2);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y;
		mpx[p[i].x]; mpy[p[i].y];
	}

	/* Coordinate Compression Crap */
	int nxt = 1;
	for (auto &x : mpx) {
		x.second = nxt;
		revx[nxt] = x.first;
		++nxt;
	}
	nxt = 1;
	for (auto &y : mpy) {
		y.second = nxt;
		revy[nxt] = y.first;
		++nxt;
	}
	for (int i = 1; i <= n; ++i) {
		p[i].x = mpx[p[i].x];
		p[i].y = mpy[p[i].y];
		x_pts[p[i].y].pb(p[i].x);
		y_pts[p[i].x].pb(p[i].y);
	}

	/* Find segments of consecutive bad intersections */
	for (int x = 1; x <= n; ++x) {
		sort(y_pts[x].begin(), y_pts[x].end());
		int k = y_pts[x].size();
		for (int i = 0; i < k - 1; ++i) {
			int y1 = y_pts[x][i], y2 = y_pts[x][i + 1];
			if (y1 == y2 - 1) {
				continue;
			}
			vt_segments.pb({x, y1 + 1, x, y2 - 1});
		}
	}
	for (int y = 1; y <= n; ++y) {
		sort(x_pts[y].begin(), x_pts[y].end());
		int k = x_pts[y].size();
		for (int i = 0; i < k - 1; ++i) {
			int x1 = x_pts[y][i], x2 = x_pts[y][i + 1];
			if (x1 == x2 - 1) {
				continue;
			}
			hz_segments.pb({x1 + 1, y, x2 - 1, y});
		}
	}

	/* Build flow network */
	int v_sz = vt_segments.size(), h_sz = hz_segments.size();
	Dinic dinic(2 + h_sz + v_sz);
	int source = 0, sink = 2 + h_sz + v_sz - 1;
	for (int i = 1; i <= h_sz; ++i) {
		dinic.AddEdge(source, i, 1);
	}
	for (int j = h_sz + 1; j <= h_sz + v_sz; ++j) {
		dinic.AddEdge(j, sink, 1);
	}
	for (int i = 0; i < h_sz; ++i) {
		for (int j = 0; j < v_sz; ++j) {
			if (in_range(hz_segments[i].y1, vt_segments[j].y1, vt_segments[j].y2) and
				in_range(vt_segments[j].x1, hz_segments[i].x1, hz_segments[i].x2)) {
				dinic.AddEdge(i + 1, j + h_sz + 1, inf);
			}
		}
	}

	/* Find min cut */
	dinic.MaxFlow(source, sink);
	dinic.find_cut(source);

	/* Use min cut to break wires */
	int h = mpy.size(), v = mpx.size();
	for (int i = 1; i <= h_sz; ++i) {
		if (!dinic.mark[i]) {
			segment mv = hz_segments[i - 1];
			brk_x[mv.y1].pb(mv.x1 - 1);
			brk_x[mv.y1].pb(mv.x2 + 1);
			++h;
		}
	}
	for (int j = h_sz + 1; j <= h_sz + v_sz; ++j) {
		if (dinic.mark[j]) {
			segment mv = vt_segments[j - h_sz - 1];
			brk_y[mv.x1].pb(mv.y1 - 1);
			brk_y[mv.x1].pb(mv.y2 + 1);
			++v;
		}
	}

	/* Output wires */
	cout << h << endl;
	for (int y = 1; y <= mpy.size(); ++y) {
		brk_x[y].pb(x_pts[y][0]);
		brk_x[y].pb(x_pts[y].back());
		sort(brk_x[y].begin(), brk_x[y].end());
		int pts = brk_x[y].size();
		for (int i = 0; i < pts; i += 2) {
			cout << revx[brk_x[y][i]] << ' ' << revy[y] << ' ';
			cout << revx[brk_x[y][i + 1]] << ' ' << revy[y] << endl;
		}
	}
	cout << v << endl;
	for (int x = 1; x <= mpx.size(); ++x) {
		brk_y[x].pb(y_pts[x][0]);
		brk_y[x].pb(y_pts[x].back());
		sort(brk_y[x].begin(), brk_y[x].end());
		int pts = brk_y[x].size();
		for (int i = 0; i < pts; i += 2) {
			cout << revx[x] << ' ' << revy[brk_y[x][i]] << ' ';
			cout << revx[x] << ' ' << revy[brk_y[x][i + 1]] << endl;
		}
	}
}

bool in_range(int x, int x1, int x2) {
	return x1 <= x and x <= x2;
}