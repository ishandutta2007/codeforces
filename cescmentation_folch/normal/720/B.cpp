#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
const ll INF = 1000000000000000000LL;
typedef pair<int, int> pi;

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


void addEdge(int i, int j, VVI& adj, vector<Edge>& E, ll cap) {
    Edge ee;
    ee.u = i;
    ee.v = j;
    ee.cap[0] = cap;
    ee.cap[1] = 0;
    adj[i].push_back((int)E.size());
    adj[j].push_back((int)E.size());
    E.push_back(ee);
}

VVI f;
VVI G;
VVI C;
VI V;

int cont;

pi dfs2(int x, int par) {
//     cerr << x+1 << ' ' << par+1 << endl;
    V[x] = 1;
    pi res = pi(-1, -1);
    for (int i = 0; i < G[x].size(); ++i) {
        int y = G[x][i];
        if (y == par or V[y] == 2) continue;
        if (V[y] == 1) {
            f[cont].push_back(C[x][i]);
//             cerr << cont << ' ' << C[x][i] << endl;
            res = pi(y, cont);
//             cerr << x+1 << ' ' << y+1 << ' ' << par + 1 << endl;
            ++cont;
            continue;
        }
        pi k = dfs2(y, x);
        if (k.second != -1) {
            f[k.second].push_back(C[x][i]);
//             cerr << k.second << ' ' << C[x][i] << endl;
            if (k.first == x) k.first = -1;
        }
        else {
            f[0].push_back(C[x][i]);
//             cerr << 0 << ' ' << C[x][i] << endl;
        }
        if (k.first != -1) res = k;
    }
    V[x] = 2;
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    cont = 1;
    G = C = VVI(n);
    V = VI(n, 0);
    f = VVI(m + 1);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        G[x].push_back(y);
        G[y].push_back(x);
        C[x].push_back(c);
        C[y].push_back(c);
    }
    dfs2(0, -1);
//     cerr << cont << endl;
    VVI adj(m + 2 + cont);
    vector<Edge> E;
    for (int i = 0; i < cont; ++i) {
        int kk = -1;
        if (i == 0) kk = 0;
        addEdge(0, m + 2 + i, adj, E, (int)f[i].size() + kk);
        for (int j = 0; j < f[i].size(); ++j) {
            addEdge(m + 2 + i, f[i][j] + 1, adj, E, 1);
        }
    }
    for (int i = 0; i < m; ++i) {
        addEdge(i + 2, 1, adj, E, 1);
    }
    cout << maxflow(0,1,adj,E) << endl;
}