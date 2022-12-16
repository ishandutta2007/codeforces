#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;


const int N = 110;
const int INF = 0x3f3f3f3f;

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

ll x[N], y[N];
int n, m, k;
ll dp[N][N], fr[N][N];
vector<pair<int, int>> edges;
bool removed[N];
const int Z = 51;
const int ss = 105, tt = 106;

pair<int, int> get_next_removal(int pre_cap) {
  for (int i=1; i<=n; ++i) {
    for (int z=0; z<=Z; z+=Z) {
      init();
      for (int j=1; j<=n; ++j) {
        if (!removed[j] && j != i+z) {
          add_edge(ss, j);
        }
        if (!removed[j+Z] && j+Z != i+z) {
          add_edge(j+Z, tt);
        }
      }
      for (auto [u, v] : edges) {
        add_edge(u, v+Z);
      }
      int cflw = flow(ss, tt);
      if (cflw < pre_cap) {
        return {i+z, cflw};
      }
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m >> k;
  for (int i=0; i<m; ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  for (int i=1; i<=k; ++i) {
    cin >> x[i] >> y[i];
  }

  int cur_cap = 0;
  {
    init();
    for (int i=1; i<=n; ++i) {
      add_edge(ss, i);
      add_edge(i+Z, tt);
    }
    for (auto& [u, v] : edges) {
      add_edge(u, v+Z);
    }
    cur_cap = flow(ss, tt);
  }
  int init_cap = cur_cap;

  int need = max(0, k-(n-cur_cap)+1);
  vector<int> removals;
  //cerr << " .. NEED " << need << endl;
  {
    while (removals.size() < need) {
      auto [q, nxt_cap] = get_next_removal(cur_cap);
      removals.push_back(q);
      removed[q] = 1;
      assert(cur_cap == nxt_cap+1);
      cur_cap = nxt_cap;
    }
  }

  for (int i=0; i<=n; ++i) {
    for (int j=0; j<=n; ++j) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = 0;
  for (int i=1; i<=k; ++i) {
    for (int j=max(0, i+1-(n-init_cap)); j<=need; ++j) {
      for (int q=0; q<=j; ++q) {
        ll tval = dp[i-1][q] + max(0LL, x[i]-y[i]*(j-q));
        if (tval > dp[i][j]) {
          fr[i][j] = q;
          dp[i][j] = tval;
        }
      }
    }
  }
  vector<int> ops;
  int r = need;
  for (int i=k; i>0; --i) {
    ops.push_back(0);
    for (int l=fr[i][r]; l<r; ++l) {
      int s = removals.back(); removals.pop_back();
      if (s >= Z) {
        s = -(s-Z);
      }
      ops.push_back(s);
    }
    //cerr << "!! r " << r << endl;
    r = fr[i][r];
  }

  reverse(ops.begin(), ops.end());
  cout << ops.size() << "\n";
  for (auto& x : ops) {
    cout << x << " ";
  }
  cout << "\n";

  return 0;
}