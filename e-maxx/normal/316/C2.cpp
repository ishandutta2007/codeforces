#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXS = 82;
const int MAXN = MAXS * MAXS;
const int dxy[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};


int n1, n2, a[MAXS][MAXS];

struct edge {
	int a, b, cap, cost, flow;
};
int n, s, t, flow, cost, par[MAXN], d[MAXN], q[MAXN];
vector<int> g[MAXN];
vector<edge> e;
bool in_q[MAXN];


void add_edge (int a, int b, int cap, int cost)
{
	edge e1 = { a, b, cap, cost, 0 };
	edge e2 = { b, a, 0, -cost, 0 };
	g[a].pb ((int)e.size());
	e.pb (e1);
	g[b].pb ((int)e.size());
	e.pb (e2);
}

bool enlarge() {
	forn(i,n) {
		d[i] = INF;
		in_q[i] = false;
	}
    int qh=0, qt=0;

	d[s] = 0;
	q[qt++] = s;
	while (qh != qt) {
		int v = q[qh++];
        if (qh == MAXN)
            qh -= MAXN;
		in_q[v] = false;

		forn(i,g[v].size()) {
			int id = g[v][i],
				to = e[id].b;
			if (e[id].flow < e[id].cap) {
				int nd = d[v] + e[id].cost;
				if (nd < d[to]) {
					if (d[to] == INF) {
						q[qt++] = to;
                        if (qt == MAXN)
                            qt -= MAXN;
                    }
					else if (!in_q[to]) {
                        --qh;
                        if (qh < 0)
                            qh += MAXN;
						q[--qh] = to;
                    }
					d[to] = nd;
					in_q[to] = true;
					par[to] = id;
				}
			}
		}
	}

	if (d[t] == INF)
		return false;

	int cflow = INF;
	for (int v=t; v!=s; ) {
		int id = par[v];
		cflow = min (cflow, e[id].cap - e[id].flow);
		v = e[id].a;
	}
	flow += cflow;
	for (int v=t; v!=s; ) {
		int id = par[v];
		e[id].flow += cflow;
		e[id^1].flow -= cflow;
		cost += e[id].cost * cflow;
		v = e[id].a;
	}
	return true;
}



bool read() {
    if (!(cin >> n1 >> n2))
        return false;
    forn(i, n1)
        forn(j, n2)
            scanf("%d", &a[i][j]);
    return true;
}


inline bool inside(int x, int y) {
    return 0<=x && x<n1 && 0<=y && y<n2;
}

void solve() {
    forn(i, MAXN)
        g[i].clear();
    e.clear();
    n = n1 * n2 + 2;
    forn(x, n1)
        forn(y, n2) {
            bool f = false;
            forn(dir, 4) {
                int nx = x + dxy[dir][0];
                int ny = y + dxy[dir][1];
                if (inside(nx, ny))
                    if (a[nx][ny] == a[x][y])
                        f = true;
            }
            forn(dir, 4) {
                int nx = x + dxy[dir][0];
                int ny = y + dxy[dir][1];
                if (inside(nx, ny))
                    add_edge(x * n2 + y, nx * n2 + ny, 1, !f || a[nx][ny] != a[x][y]);
            }
        }
    s = n - 2;
    t = n - 1;
    forn(x, n1)
        forn(y, n2)
            if ((x + y) % 2 == 0)
                add_edge(s, x * n2 + y, 1, 0);
            else
                add_edge(x * n2 + y, t, 1, 0);

	flow = cost = 0;
	while (enlarge())
		;

    if (flow != n1 * n2 / 2)
        throw;

    cout << cost << endl;
}


int main(int argc, char* argv[]) {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
    while (read())
        solve();
#else
    if (!read())
        throw;
    solve();
#endif
}