#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

/*
using vi=vector<int>;
#define rep(i, a, b) for(int i=a; i<b; ++i)

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}
*/



const int N = 200200;
namespace SCC{
int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; }while (v != u);
    ++scompNum; }}
void get_scc(int n) {
  memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }

  }

vector<pair<int, ll>> adj[N];
int gof[N];


ll dep[N];
ll comp_gcd[N];
void dfs(int u, int g, ll d) {
  if (dep[u]) {
    comp_gcd[g] = __gcd(comp_gcd[g], abs(dep[u]-d));
    return;
  }
  dep[u] = d;
  for (auto& [v, l] : adj[u]) {
    if (g != gof[v]) continue;
    dfs(v, g, d+l);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj_scc(n+1);
  for (int i=1; i<=m; ++i) {
    int u, v;
    ll l;
    cin >> u >> v >> l;
    adj[u].push_back({v, l});
    SCC::adj[u].push_back(v);
  }
  SCC::get_scc(n+1);
  for (int i=1; i<=n; ++i) {
    gof[i] = SCC::scomp[i];
  }
  for (int i=1; i<=n; ++i) {
    if (!dep[i]) {
      dfs(i, gof[i], 1);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    ll v, s, t;
    cin >> v >> s >> t;
    ll g = comp_gcd[gof[v]];
    if (g == 0) {
      cout << (s == 0 ? "YES" : "NO") << "\n";
    } else {
      ll h = __gcd(g, t);
      cout << ((t-s)%h == 0 ? "YES" : "NO") << "\n";
    }
  }

  return 0;
}