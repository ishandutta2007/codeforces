#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 3030;

struct Edge { int v, r; ll f, c, p; };
vector<Edge> adj[N]; int sz[N]; ll mc;
vector<Edge> mcf_edges; // for mcf on large graphs with negative costs
void init(int n=N) {
  mc=0; fill(sz,sz+n,0); fill(adj,adj+n,vector<Edge>()); }
void add_edge(int a, int b, ll c=1, ll p=0) { mc = max(mc,c); // scaling
  // mcf_edges.push_back({b,a,0,c,p});
	adj[a].push_back({b,sz[b]++,0,c,p});
	adj[b].push_back({a,sz[a]++,0,0,-p}); }

int L[N], cur[N], Q[N];
const int INF = 0x3f3f3f3f;
bool bfs(int s, int t, ll lim=1) {
  memset(L, INF, sizeof L); memset(cur, 0, sizeof cur);
  int f,b; Q[f=b=0] = s; L[s] = 0;
  while(f<=b && L[t]==INF) { int u = Q[f++];
    for(const Edge& e:adj[u]) if(L[e.v] == INF && e.c-e.f >= lim) {
      Q[++b] = e.v; L[e.v] = L[u]+1; } } return L[t] < INF; }
ll dfs(int u, int t, ll f) { if (u == t || !f) return f;
  for (int i = cur[u]; i < sz[u]; cur[u] = ++i) { Edge& e = adj[u][i];
    if(e.f<e.c && L[e.v]==L[u]+1) {
      if(ll cf = dfs(e.v, t, min(e.c-e.f, f))) {
        e.f += cf; adj[e.v][e.r].f -= cf; return cf; } } } return 0; }
ll flow(int s, int t, bool scaling=0) {ll inf=numeric_limits<ll>::max();
  ll res = 0; for(ll lim=(scaling?mc:1); lim; lim/=2) {
    while(bfs(s,t,lim))while(ll cf=dfs(s,t,inf))res += cf;} return res;}

int a[N], b[N];
int lst[N];
int n;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  int ss = n+1, tt=n+2;
  init(tt+10);
  ll possum = 0;
  for (int i=1; i<=n; ++i) {
    if (b[i] > 0) {
      add_edge(ss, i, b[i]);
      possum += b[i];
    } else {
      add_edge(i, tt, -b[i]);
    }
  }
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=a[i]; ++j) {
      if (a[i]%j == 0) {
        add_edge(i, lst[j], 1e13);
      }
    }
    lst[a[i]] = i;
  }
  ll f = flow(ss, tt);
  cout << possum - f << "\n";
  
  return 0;
}