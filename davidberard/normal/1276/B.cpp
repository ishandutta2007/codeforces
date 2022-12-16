#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)

#define sz(x) (int)(x).size()

/**
 * Author: Simon Lindholm
 * Date: 2017-04-17
 * License: CC0
 * Source: folklore
 * Description: Finds all biconnected components in an undirected graph, and
 *  runs a callback for the edges in each. In a biconnected component there
 *  are at least two distinct paths between any two nodes. Note that a node can
 *  be in several components. An edge which is not in a component is a bridge,
 *  i.e., not part of any cycle.
 * Time: O(E + V)
 * Status: tested during MIPT ICPC Workshop 2017
 * Usage:
 *  int eid = 0; ed.resize(N);
 *  for each edge (a,b) {
 *    ed[a].emplace_back(b, eid);
 *    ed[b].emplace_back(a, eid++); }
 *  bicomps([\&](const vi\& edgelist) {...});
 */

typedef vector<int> vi;

vi num, st;
vector<vector<pii>> ed;
int Time;
template<class F>
int dfs(int at, int par, F& f) {
	int me = num[at] = ++Time, e, y, top = me;
	trav(pa, ed[at]) if (pa.second != par) {
		tie(y, e) = pa;
		if (num[y]) {
			top = min(top, num[y]);
			if (num[y] < me)
				st.push_back(e);
		} else {
			int si = sz(st);
			int up = dfs(y, e, f);
			top = min(top, up);
			if (up == me) {
				st.push_back(e);
                //cerr << " !! " << endl;
				f(vi(st.begin() + si, st.end()));
				st.resize(si);
			}
			else if (up < me) st.push_back(e);
			else { /* e is a bridge */ }
		}
	}
	return top;
}

template<class F>
void bicomps(F f) {
    num.clear();
    st.clear();
    Time = 0;
	num.assign(sz(ed), 0);
	rep(i,0,sz(ed)) if (!num[i]) dfs(i, -1, f);
}

const int N = 200200;
const int M = 500500;

namespace n9 {
//*/
int vcompNum,ecompNum,I,m;
int first[N],low[N],vis[N],ecomp[N];
int nxt[2*M],ep[2*M],vcomp[2*M];
stack<int> edges, verts;
void init(int n) {
    m = 0; memset(first, -1, sizeof(int)*n);
    I = 0;
    vcompNum = 0; ecompNum = 0;
}
void add_edge(int a, int b) {
    nxt[m] = first[ep[m] = a], first[ep[m]] = m, ++m;
    nxt[m] = first[ep[m] = b], first[ep[m]] = m; ++m; }
void biconnected(int u, int par){ int v,E; low[u] = vis[u] = ++I; verts.push(u);
  for (int e = first[u]; e != -1; e = nxt[e]) { v = ep[e^1];
    if (!vis[v]) { edges.push(e); biconnected(v,e); low[u] = min(low[u],low[v]);
      if (vis[u] <= low[v]) { // u is a cut vertex unless it's a one-child root
        do { E = edges.top(); edges.pop(); vcomp[E] = vcomp[E^1] = vcompNum; }
        while (e != E && e != (E^1)); ++vcompNum; }}
    else if (vis[v] < vis[u] && e != (par^1)) {
      low[u] = min(low[u], vis[v]); edges.push(e); }
    else if (v == u) vcomp[e] = vcomp[e^1] = vcompNum++; } // e is a self-loop
  if (vis[u] <= low[u]) { // par is a cut edge unless par==-1
    do { v = verts.top(); verts.pop(); ecomp[v] = ecompNum; }
    while (v != u); ++ecompNum; }
}
void get_bcc(int n) { assert(edges.empty()); assert(verts.empty()); memset(vis,0,sizeof(int)*n); vcompNum=ecompNum=I=0;
  for (int i=0; i<n; ++i) if (!vis[i]) biconnected(i, -1);
}
// tree-independent criteria for identifying articulation points and bridges
bool isCutVertex(int u) { for (int e = first[u]; e != -1; e = nxt[e])
  if (vcomp[e] != vcomp[first[u]]) return true; return false; }
bool isCutEdge(int e) { return ecomp[ep[e]] != ecomp[ep[e^1]]; }
//*!
}

int n, m, a, b;
//vector<int> adj[N];

bool ab_together;
void check_ab(const vector<int>& comp) {
    //cerr << " CAB ";
    //for (auto& x : comp) { //cerr << x << " "; }
    //cerr << endl;
    /*
    bool has_a = 0, has_b = 0;
    for (auto& x : comp) {
        has_a |= (x == a);
        has_b |= (x == b);
    }
    ab_together |= (has_a && has_b);
    */
}

int sz[N];
int par[N];
int vis2[N];

void dfs2(int u, int p) {
    if (vis2[u]) return;
    ////cerr << " par " << u << " = " << p << endl;
    vis2[u] = 1;
    sz[u] = 1;
    par[u] = p;
    for (auto& pr : ed[u]) {
        int v = pr.first;
        if (v == p) continue;
        if (vis2[v]) continue;
        dfs2(v, u);
        ////cerr << " :: ch " << v << " Of " << u << endl;
        sz[u] += sz[v];
    }
    //cerr << "   SZ " << u << " " << sz[u] << endl;
}

void solve() {
    cin >> n >> m >> a >> b;
    ab_together = 0;
    n9::init(n+1);
    ed.resize(n+1);
    for (int i=0; i<=n; ++i) {
        ed[i].clear();
        vis2[i] = 0;
    }

    int eid = 0;
    for (int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        //cerr << "   ~~ " << eid << " " << u << " " <<v << endl;
        ed[u].emplace_back(v, eid);
        ed[v].emplace_back(u, eid++);
        n9::add_edge(u, v);
    }

    n9::get_bcc(n+1);

    if (!n9::isCutVertex(a) || !n9::isCutVertex(b)) {
        cout << 0 << "\n";
        return;
    }

    //////cerr <<" !! " << endl;

    dfs2(a, -1);
    int z = b;
    while (par[z] != a) {
        z = par[z];
    }
    ll fx = sz[a] - sz[z] - 1;

    for (int i=1; i<=n; ++i) {
        vis2[i] = 0;
    }
    dfs2(b, -1);
    z = a;
    while (par[z] != b) {
        z = par[z];
    }

    ll fy = sz[b] - sz[z] - 1;

    ////cerr << " :: " << fx << " " << fy  << " :: " << a << " " << z << " :: " << sz[a] << " - " << sz[z] << " " << sz[b] << endl;
    
    cout << fx*fy << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while (TT--) {
        solve();
    }
    return 0;
}