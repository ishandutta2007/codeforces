#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
using namespace std;

// CAREFUL WITH CONSTANTS
const int INF = 1000000000;

vector<int> hung(const vector< vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    vector<vector<long long> > a(n + 1);
    a[0] = vector<long long>(m + 1);
    for (int i = 0; i < n; ++i) {
        a[i + 1].push_back(100LL * INF);
        for (int j = 0; j < m; ++j) {
            a[i + 1].push_back(A[i][j]);
        }
    }
    vector<long long> u(n+1), v(m+1);
    vector<int> p(m+1), way(m+1);
    for (int i=1; i<=n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<long long> minv (m+1, 100LL * INF);
        vector<char> used (m+1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], j1;
            long long delta = 100LL * INF;
            for (int j=1; j<=m; ++j)
                if (!used[j]) {
                    long long cur = a[i0][j]-u[i0]-v[j];
                    if (cur < minv[j])
                        minv[j] = cur,  way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j],  j1 = j;
                }
            for (int j=0; j<=m; ++j)
                if (used[j])
                    u[p[j]] += delta,  v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);
        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    vector<int> rv(n);
    for (int j = 1; j <= m; ++j) {
        rv[p[j] - 1] = j - 1;
    }
    return rv;
}

struct MinCostFlow {

struct edge {
	int b, u, c, f;
	size_t back;
};

int n, m;
vector < vector<edge> > g;

MinCostFlow(int n) : n(n), m(0), g(n) {}

// a, b, cap, cost
void add_edge(int a, int b, int u, int c) {
    ++m;
	edge r1 = { b, u, c, 0, g[b].size() };
	edge r2 = { a, 0, -c, 0, g[a].size() };
	g[a].push_back (r1);
	g[b].push_back (r2);
}

int flow(int s, int t, int k) {
	int flow = 0,  cost = 0;
	while (flow < k) {
		vector<int> id (n, 0);
		vector<int> d (n, INF);
		vector<int> q (n);
		vector<int> p (n);
		vector<size_t> p_edge (n);
		int qh=0, qt=0;
		q[qt++] = s;
		d[s] = 0;
		while (qh != qt) {
			int v = q[qh++];
			id[v] = 2;
			if (qh == n)  qh = 0;
			for (size_t i=0; i<g[v].size(); ++i) {
				edge & r = g[v][i];
				if (r.f < r.u && d[v] + r.c < d[r.b]) {
					d[r.b] = d[v] + r.c;
					if (id[r.b] == 0) {
						q[qt++] = r.b;
						if (qt == n)  qt = 0;
					}
					else if (id[r.b] == 2) {
						if (--qh == -1)  qh = n-1;
						q[qh] = r.b;
					}
					id[r.b] = 1;
					p[r.b] = v;
					p_edge[r.b] = i;
				}
			}
		}
		if (d[t] == INF)  break;
		int addflow = k - flow;
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_edge[v];
			addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
		}
		for (int v=t; v!=s; v=p[v]) {
			int pv = p[v];  size_t pr = p_edge[v],  r = g[pv][pr].back;
			g[pv][pr].f += addflow;
			g[v][r].f -= addflow;
			cost += g[pv][pr].c * addflow;
		}
		flow += addflow;
	}	//output result
    if (flow < k) {
        return -1;
    }
    return cost;
}
};

const int MAXN = 30000;

struct Dinic {
 
struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];

Dinic(int n) : n(n) {}
 
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int flow(int S, int T) {
    s = S;
    t = T;
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

};

// Simple flow class. In a class to keep state clean.
// Interface: add_edge, flow. After calling flow, do not use!
// Graph represented by list of edges. Each edge has a pointer
// to next edge for the same starting node. Each node - pointer to
// first edge.
struct MaxFlow {
    struct Edge {
        int to, c, ne;
        Edge(int to, int c, int ne) : to(to), c(c), ne(ne) {}
    };

    int n;
    vector<Edge> ed;
    vector<int> fi;

    MaxFlow(int n) : n(n), ed(), fi(n, -1) {}

    void add_edge(int a, int b, int c) {
        ed.push_back(Edge(b, c, fi[a]));
        fi[a] = (int) ed.size() - 1;
        ed.push_back(Edge(a, c, fi[b]));
        fi[b] = (int) ed.size() - 1;
    }

    vector<char> us;

    int dfs(int v, int tar, int cur, int minv = 1) {
        if (v == tar) return cur;
        if (us[v]) return 0;
        us[v] = 1;
        for (int i = fi[v]; i != -1; i = ed[i].ne) {
            if (ed[i].c < minv) {
                continue;
            }
            int tmp = dfs(ed[i].to, tar, min(cur, ed[i].c), minv);
            if (tmp > 0) {
                ed[i].c -= tmp;
                ed[i^1].c += tmp;
                return tmp;
            }
        }
        return 0;
    }

    int flow(int s, int t) {
        int ans = 0, cur, mv = 1;
        for (int i = 0; i < 2; ++i) {
            do {
                us = vector<char>(n);
                cur = dfs(s, t, INF, mv);
                ans += cur;
            } while (cur);
        }
        return ans;
    }
};

// Minimum flow in a graph. Each edge has mincap, maxcap.
// No cost, just flow.
// Check if a flow size >= m exists: remove mincap from
// all edges. Add edge cap m from t to s.
struct BoundedMinFlow {
    vector<int> a, b;
    vector<int> l, r;
    int n;

    BoundedMinFlow(int n) : n(n) {}
    
    void add_edge(int f, int t, int minc, int maxc) {
        a.push_back(f);
        b.push_back(t);
        l.push_back(minc);
        r.push_back(maxc);
    }

    bool check(int s, int t, int m) {
        MaxFlow f(n + 2);
        f.add_edge(t, s, m);
        int total = 0;
        for (int i = 0; i < (int) a.size(); ++i) {
            if (l[i] > 0) {
                f.add_edge(n, b[i], l[i]);
                f.add_edge(a[i], n + 1, l[i]);
                total += l[i];
            }
            if (r[i] > l[i]) {
                f.add_edge(a[i], b[i], r[i] - l[i]);
            }
        }
        return (f.flow(n, n + 1) == total);
    }

    int flow(int s, int t) {
        int le = -1, ri = 10000;
        if (!check(s, t, ri)) {
            return -1;
        }
        while (le + 1 < ri) {
            int mi = (le + ri);
            if (check(s, t, mi)) {
                ri = mi;
            } else {
                le = mi;
            }
        }
        return ri;
    }
};

int h, w;
string va[16] = {"BY", "BW", "BR", "BB",
                 "RY", "RW", "RR",
                 "WY", "WW",
                 "YY"};

char vv[16][2];

char st[16][16][4][2];

int cnt[16];

struct pos {
    int sx, sy, ex, ey;
    int id;
    pos() {}
    pos(int SX, int SY, int EX, int EY, int ID) : sx(SX), sy(SY), ex(EX), ey(EY), id(ID) {}
    bool operator<(const pos &p) const {
        return id < p.id;
    }
};

map< vector<int>, vector<pos> > mp;
char t[16][16];

int lp;
vector<pos> p(28);

vector<int> cur;
bool us[16][16];

int dif[16][16];

char ou[32][32];

int gk[32][32][2];

void prec() {
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c + 1 < w; ++c) {
            int k = -1;
            for (int i = 0; i < 10; ++i) {
                if ((st[r][c][0][0] == vv[i][0] && st[r][c][0][1] == vv[i][1])
                    || (st[r][c][1][0] == vv[i][0] && st[r][c][1][1] == vv[i][1])) {
                    k = i;
                    break;
                }
            }
            gk[r][c][0] = k;
        }
    }
    for (int r = 0; r + 1 < h; ++r) {
        for (int c = 0; c < w; ++c) {
            int k = -1;
            for (int i = 0; i < 10; ++i) {
                if ((st[r][c][2][0] == vv[i][0] && st[r][c][2][1] == vv[i][1])
                    || (st[r][c][3][0] == vv[i][0] && st[r][c][3][1] == vv[i][1])) {
                    k = i;
                    break;
                }
            }
            gk[r][c][1] = k;
        }
    }
}

void go(int r, int c) {
    if (r >= h) {
        if (mp.find(cur) != mp.end()) {
            return;
        }
        mp[cur] = p;
        return;
    }
    if (c >= w) {
        go(r + 1, 0);
        return;
    }
    if (us[r][c]) {
        go(r, c + 1);
        return;
    }
    if (!us[r][c + 1] && c + 1 < w) {
        us[r][c] = us[r][c + 1] = 1;
        int k = gk[r][c][0];
        // for (int i = 0; i < 10; ++i) {
        //     if ((st[r][c][0][0] == vv[i][0] && st[r][c][0][1] == vv[i][1])
        //         || (st[r][c][1][0] == vv[i][0] && st[r][c][1][1] == vv[i][1])) {
        //         k = i;
        //         break;
        //     }
        // }
        cur[k]++;
        p[lp].sx = r;
        p[lp].sy = c;
        p[lp].ex = r;
        p[lp].ey = c + 1;
        p[lp].id = k;
        ++lp;
        go(r, c + 2);
        cur[k]--;
        --lp;
        us[r][c] = us[r][c + 1] = 0;
    }

    if (!us[r + 1][c] && r + 1 < h) {
        us[r][c] = us[r + 1][c] = 1;
        int k = gk[r][c][1];
        // for (int i = 0; i < 10; ++i) {
        //     if ((st[r][c][2][0] == vv[i][0] && st[r][c][2][1] == vv[i][1])
        //         || (st[r][c][3][0] == vv[i][0] && st[r][c][3][1] == vv[i][1])) {
        //         k = i;
        //         break;
        //     }
        // }
        cur[k]++;
        p[lp].sx = r;
        p[lp].sy = c;
        p[lp].ex = r + 1;
        p[lp].ey = c;
        p[lp].id = k;
        ++lp;
        go(r, c + 1);
        cur[k]--;
        --lp;
        us[r][c] = us[r + 1][c] = 0;
    }
}

int main() {
    h = 7;
    w = 8;
    for (int i = 0; i < h; ++i) {
        scanf("%s", t[i]);
    }
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &cnt[i]);
    }
    cur = vector<int>(10, 0);
    memset(us, 0, sizeof(us));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j + 1 < w; ++j) {
            st[i][j][0][0] = t[i][j];
            st[i][j][0][1] = t[i][j + 1];
            st[i][j][1][0] = t[i][j + 1];
            st[i][j][1][1] = t[i][j];
        }
    }
    for (int i = 0; i + 1 < h; ++i) {
        for (int j = 0; j < w; ++j) {
            st[i][j][2][0] = t[i][j];
            st[i][j][2][1] = t[i + 1][j];
            st[i][j][3][0] = t[i + 1][j];
            st[i][j][3][1] = t[i][j];
        }
    }
    for (int i = 0; i < 10; ++i) {
        vv[i][0] = va[i][0];
        vv[i][1] = va[i][1];
    }
    prec();
    go(0, 0);
    
    memset(dif, 0, sizeof(dif));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            dif[i][j] = min((va[i][0] != va[j][0]) + (va[i][1] != va[j][1]),
                            (va[i][0] != va[j][1]) + (va[i][1] != va[j][0]));
        }
    }

    int bsol = (1 << 20);
    MinCostFlow be(1);
    vector<pos> bp;
    for (map< vector<int>, vector<pos> >::iterator it = mp.begin(); it != mp.end(); ++it) {
        MinCostFlow f(22);
        for (int i = 0; i < 10; ++i) {
            f.add_edge(20, i, cnt[i], 0);
            f.add_edge(10 + i, 21, it->first[i], 0);
        }
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                f.add_edge(i, j + 10, INF, dif[i][j]);
            }
        }
        int k = f.flow(20, 21, 28);
        if (k < bsol) {
            bsol = k;
            be = f;
            bp = it->second;
        }
    }
    printf("%d\n", 56 - bsol);
    memset(ou, '.', sizeof(ou));
    for (int i = 0; i < (int) bp.size(); ++i) {
        int nd = bp[i].id + 10;
        for (int j = 0; j < (int) be.g[nd].size(); ++j) {
            MinCostFlow::edge &ed = be.g[nd][j];
            if (ed.b < 10 && ed.f < 0) {
                ++ed.f;
                int c1 = (va[ed.b][0] != t[bp[i].sx][bp[i].sy]) + (va[ed.b][1] != t[bp[i].ex][bp[i].ey]);
                int c2 = (va[ed.b][1] != t[bp[i].sx][bp[i].sy]) + (va[ed.b][0] != t[bp[i].ex][bp[i].ey]);
                if (c1 <= c2) {
                    ou[2 * bp[i].sx][2 * bp[i].sy] = va[ed.b][0];
                    ou[2 * bp[i].ex][2 * bp[i].ey] = va[ed.b][1];
                } else {
                    ou[2 * bp[i].sx][2 * bp[i].sy] = va[ed.b][1];
                    ou[2 * bp[i].ex][2 * bp[i].ey] = va[ed.b][0];
                }
                if (bp[i].sx == bp[i].ex) {
                    ou[2 * bp[i].sx][2 * bp[i].sy + 1] = '-';
                } else {
                    ou[2 * bp[i].sx + 1][2 * bp[i].sy] = '|';
                }
                break;
            }
        }
    }
    for (int i = 0; i < 2 * h - 1; ++i) {
        ou[i][2 * w - 1] = '\0';
        printf("%s\n", ou[i]);
    }
    return 0;
}