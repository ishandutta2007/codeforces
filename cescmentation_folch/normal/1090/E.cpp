#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

typedef long long ll;
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

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  for (int i=0; i<int(E.size()); ++i) E[i].flow = 0;
  ll flow = 0, bot;
  while (bfs(s, t, adj, E)) {
    act = VI(adj.size(), 0);
    while ((bot = dfs(s,t,INF, adj, E))) flow += bot;
  }
  return flow;
}

void addEdge(int u, int v, int cap, vvi& adj, vector<Edge>& E) {
  Edge e;
  e.u = u; e.v = v;
  e.cap[0] = cap;
  e.cap[1] = 0;
  adj[u].push_back((int)E.size());
  adj[v].push_back((int)E.size());
  E.push_back(e);
}

inline int node(int a, int b) {
  return 8*a + b;
}

inline string topar(int n) {
  int a = n/8;
  int b = n%8;
  string r(2,' ');
  r[0] = 'a' + b;
  r[1] = '1' + a;
  return r;
}

inline int parto(string r) {
  int a = r[1] - '1';
  int b = r[0] - 'a';
  return node(a,b);
}

int M[64];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int sz = 8*8 + 2;
  vvi adj(sz);
  vector<Edge> E;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (i > 1 and j) addEdge(node(i,j), node(i-2,j-1), sz, adj, E); 
      if (i > 1 and j < 7) addEdge(node(i,j), node(i-2,j+1), sz, adj, E); 
      if (i < 6 and j) addEdge(node(i,j), node(i+2,j-1), sz, adj, E); 
      if (i < 6 and j < 7) addEdge(node(i,j), node(i+2,j+1), sz, adj, E); 
      if (j > 1 and i) addEdge(node(i,j), node(i-1,j-2), sz, adj, E); 
      if (j > 1 and i < 7) addEdge(node(i,j), node(i+1,j-2), sz, adj, E); 
      if (j < 6 and i) addEdge(node(i,j), node(i-1,j+2), sz, adj, E); 
      if (j < 6 and i < 7) addEdge(node(i,j), node(i+1,j+2), sz, adj, E); 
    }
  }
  int n;
  cin >> n;
  int s = sz-2;
  int t = sz-1;
  for (int i = 0; i < n; ++i) {
    addEdge(i, t, 1, adj, E);
  }
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    int ind = parto(a);
    M[ind] = 1;
    addEdge(s, ind, 1, adj, E);
  }
  maxflow(s,t,adj,E);
  int cont = 1;
  vector<string> R;
  while (cont) {
    cont = 0;
    for (auto& e : E) {
      if (e.flow and e.u < 64 and e.v < 64 and M[e.u] and !M[e.v]) {
        --e.flow;
        M[e.v] = 1;
        M[e.u] = 0;
        ++cont;
        R.push_back(topar(e.u) + "-" + topar(e.v));
      }
    }
  }
  cout << (int)R.size() << '\n';
  for (auto x : R) cout << x << '\n';
}