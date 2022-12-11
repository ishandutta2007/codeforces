#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<int, pi> ppi;
typedef vector<ppi> vppi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

typedef vector<int> VI;
typedef vector<VI> VVI;
const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge { int u, v; ll cap[2], flow; };

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
  queue<int> Q;
  d = VI(adj.size(), -1);
  d[t] = 0;
  Q.push(t);
  while (not Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < int(adj[u].size()); ++i) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(v, e) > 0 and d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
  return d[s] >= 0;
}

ll dfs(int u,int t,ll bot,VVI& adj,vector<Edge>& E) {
  if (u == t) return bot;
  for (; act[u] < int(adj[u].size()); ++act[u]) {
    int e = adj[u][act[u]];
    if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
      ll inc=dfs(VEI(u,e),t,min(bot,CAP(u,e)),adj,E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

ll flow;
ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  //for (int i=0; i<int(E.size()); ++i) E[i].flow = 0;
  ll bot;
  while (bfs(s, t, adj, E)) {
    act = VI(adj.size(), 0);
    while ((bot = dfs(s,t,INF, adj, E))) flow += bot;
  }
  return flow;
}

void addEdge(int x, int y, ll c, vvi& adj, vector<Edge>& E) {
  //cerr << x << ' ' << y << ' ' << c << endl;
  Edge e;
  e.u = x;
  e.v = y;
  e.cap[0] = c;
  e.cap[1] = 0;
  e.flow = 0;
  adj[x].push_back((int)E.size());
  adj[y].push_back((int)E.size());
  E.push_back(e);
}

vvpi G;
vi D;

void dijkstra(int x) {
  priority_queue<pi> Q;
  Q.push(pi(0, x));
  D[x] = 0;
  while (!Q.empty()) {
    int y = Q.top().second;
    int d = -Q.top().first;
    Q.pop();
    if (d != D[y]) continue;
    for (auto it : G[y]) {
      int z = it.first;
      int w = it.second;
      if (D[z] == -1 or D[z] > D[y] + w) {
        D[z] = D[y] + w;
        Q.push(pi(-D[z], z));
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  flow = 0;
  int v, e, n, k;
  cin >> v >> e >> n >> k;
  vi C(v, 0);
  for (int i = 0; i < n; ++i) {
    int x; 
    cin >> x;
    --x;
    ++C[x];
  }
  vi H(v, -1);
  int cont = 0;
  for (int i = 0; i < v; ++i) {
    if (C[i]) {
      H[i] = cont++;
    }
  }
  G = vvpi(v);
  for (int i = 0; i < e; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a; --b;
    G[a].push_back(pi(b, w));
    G[b].push_back(pi(a, w));
  }
  int sz = v + cont + 2;
  vvi adj(sz);
  vector<Edge> E;
  int s = sz-2;
  int t = sz-1;
  for (int i = 0; i < v; ++i) addEdge(i, t, 1, adj, E);
  vppi B;
  for (int i = 0; i < v; ++i) {
    if (H[i] != -1) {
      addEdge(s, v+H[i], C[i], adj, E);
      D = vi(v, -1);
      dijkstra(i);
      for (int j = 0; j < v; ++j) {
        if (D[j] != -1) B.push_back(ppi(D[j], pi(H[i], j)));
      }
    }
  }
  sort(B.begin(), B.end());
  B.push_back(ppi(-1,pi(0,0)));
  int ant = B[0].first;
  int res = -1;
  for (auto it : B) {
    if (ant != it.first) {
      if (maxflow(s, t, adj, E) >= k) {
        res = ant;
        break;
      }
      ant = it.first;
    }
    addEdge(v + it.second.first, it.second.second, 1, adj, E);
  }
  cout << res << '\n';
}