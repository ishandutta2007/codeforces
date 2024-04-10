#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<ll, ll> pli;

const ll INF = 100000000000ll;

#define VEI(w,e) ((E[e].u == w)? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w)? E[e].cap - E[e].flow : E[e].flow)
#define COST(w,e) ((E[e].u == w)? E[e].cost : -E[e].cost)
#define POT(u,v) (pot[u] - pot[v])
#define ADD(w,e,f) E[e].flow += ((E[e].u==w)? (f) : (-(f)))

struct Edge {
  int u, v;
  ll cap;
  ll cost;
  ll flow;
};

vi pare; 
vll d, pot;

bool dijkstra(int s, int t, vvi& adj, vector<Edge>& E) {
  pare = vi(adj.size(), -1);
  d = vll(adj.size(), INF);
  d[s] = 0;
  priority_queue<pli> Q;
  Q.push(pli(0,s));
  while (not Q.empty()) {
    int u = (int)Q.top().second;
    ll dist = -Q.top().first;
    Q.pop();
    if (dist != d[u]) continue;
    for (int i = 0; i < (int)adj[u].size(); ++i) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(u,e) and d[v] > d[u] + POT(u,v) + COST(u,e)) {
        d[v] = d[u] + POT(u,v) + COST(u,e);
        Q.push(pli(-d[v], v));
        pare[v] = e;
      }
    }
  }
  for (int i = 0; i < (int)adj.size(); ++i)
    if (pot[i] < INF) pot[i] += d[i];
  return pare[t] >= 0;
}
pli maxmin(int s, int t, vvi& adj, vector<Edge>& E) {
  ll flow = 0, cost = 0;
  for (int i = 0; i < (int)E.size(); ++i) E[i].flow = 0;
  pot = vll(adj.size(), 0);
  while (dijkstra(s, t, adj, E)) {
    ll bot = INF;
    int v = t;
    while (pare[v] != -1) {
      int e = pare[v], u = VEI(v,e);
      bot = min(CAP(u,e), bot);
      v = u;
    }
    v = t;
    while (pare[v] != -1) {
      int e = pare[v], u = VEI(v,e);
      ADD(u,e,bot);
      cost += bot*COST(u,e);
      v = u;
    }
    flow += bot;
  }
  return pli(flow, cost);
}
pli negative_edges(int s, int t, vvi& adj, vector<Edge>& E) {
  for (int i = 0; i < (int)E.size(); ++i) E[i].flow = 0;
  vll dist(adj.size(), INF);
  dist[s] = 0;
  for (int k = 0; k < (int)adj.size(); ++k) {
    for (int x = 0; x < (int)adj.size(); ++x) {
      for (int j = 0; j < (int)adj[x].size(); ++j) {
        int e = adj[x][j], y = VEI(x,e);
        if (CAP(x,e) == 0) continue;
        dist[y] = min(dist[x] + COST(x,e), dist[y]);
      }}}
  for (int x = 0; x < (int)adj.size(); ++x) {
    for (int j = 0; j < (int)adj[x].size(); ++j) {
      int e = adj[x][j], y = VEI(x,e);
      if (CAP(x,e) == 0) continue;
      E[e].cost += dist[x] - dist[y];
    }
  }
  ll flow, cost;
  tie(flow, cost) = maxmin(s, t, adj, E);
  cost += flow*dist[t];
  return pli(flow, cost);
}

void addEdge(int u, int v, ll cap, ll cost, vvi& adj, vector<Edge>& E) {
  Edge e;
  e.u = u, e.v = v, e.cap = cap, e.cost = cost;
  adj[u].push_back((int)E.size());
  adj[v].push_back((int)E.size());
  E.push_back(e);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string a;
  cin >> a;
  int m;
  cin >> m;
  vector<Edge> E;
  vvi adj(n+2);
  for (int i = 0; i < m; ++i) {
    string b;
    int val;
    cin >> b >> val;
    int sz = (int)b.size();
    for (int j = 0; j + sz <= n; ++j) {
      bool pot = true;
      for (int w = 0; w < sz; ++w) {
        if (a[j + w] != b[w]) {
          pot = false;
          break;
        }
      }
      if (pot) {
        int x = j+1;
        int y = x + sz; 
        addEdge(x,y,1,-val, adj, E);
      }
    }
  }
  int x;
  cin >> x;
  for (int i = 0; i <= n; ++i) {
    addEdge(i,i+1,x,0,adj, E);
  }
  auto res = negative_edges(0, n+1, adj, E);
  assert(res.first == x);
  cout << -res.second << '\n';
}