#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
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

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  for (int i=0; i<int(E.size()); ++i) E[i].flow = 0;
  ll flow = 0, bot;
  while (bfs(s, t, adj, E)) {
    act = VI(adj.size(), 0);
    while ((bot = dfs(s,t,INF, adj, E))) flow += bot;
  }
  return flow;
}

void addEdge(int x,int y,ll c,vvi& adj,vector<Edge>& E) {
    Edge e; e.u = x; e.v = y;
    e.cap[0] = c; e.cap[1] = 0; 
    adj[x].push_back((int)E.size()); adj[y].push_back((int)E.size());
    E.push_back(e);
}


vi Tree;
vi Par;

void bul(int node, int a, int b, int& val) {
  if (a==b) {
    Tree[node] = a;
    return;
  }
  Tree[node] = val++;
  int mid = (a+b)/2;
  bul(2*node, a, mid, val);
  bul(2*node+1, mid+1, b, val);
}

void fes(int node, int a, int b, int x, int y, int po, vvi& adj, vector<Edge>& E) {
  if (b < x or y < a) return;
  if (x <= a and b <= y) {
    addEdge(Tree[node], po, 1, adj, E);
    return;
  }
  int mid = (a+b)/2;
  fes(2*node, a, mid,x,y,po,adj,E);
  fes(2*node+1,mid+1,b,x,y,po,adj,E);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  Tree = vi(6*n, -1);
  Par = Tree;
  int val = n;
  bul(1, 0, n-1, val);
  int sz = val + m + 2;
  vvi adj(sz);
  int s = sz-2;
  int t = sz-1;
  vector<Edge> E;


  for (int i = 1; i < 3*n; ++i) {
    if (Tree[i] != -1 and Tree[2*i] != -1) {
      Par[Tree[i]] = (int)E.size();
      //cerr << Tree[i] << ' ' << Par[Tree[i]] << endl;
      addEdge(Tree[2*i], Tree[i], n, adj, E);
      addEdge(Tree[2*i+1], Tree[i], n, adj, E);
    }
  }

  vi T(m);
  vi V(n,0);
  int ttbom = 0;

  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    T[i] = k;
    if (k == 0) {
      addEdge(val + i, t, 1, adj, E);
      int si;
      cin >> si;
      for (int j = 0; j < si; ++j) {
        int x;
        cin >> x;
        --x;
        addEdge(x, val+i, 1, adj, E);
      }
    }
    else if (k == 1) {
      addEdge(val+i, t, 1, adj, E);
      int l, r;
      cin >> l >> r;
      --l; --r;
      fes(1, 0, n-1, l, r, val+i, adj, E);
    }
    else {
      ++ttbom;
      addEdge(s, val + i, 1, adj, E);
      for (int j = 0; j < 3; ++j) {
        int x;
        cin >> x;
        --x;
        V[x] = 1;
        addEdge(val+i, x, 1, adj, E);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!V[i]) addEdge(s, i, 1, adj, E);
  }

  int res = (int)maxflow(s, t, adj, E) + 2*ttbom;

  cout << res << '\n';

  for (int i = 0; i < m; ++i) {
    //cerr << T[i] << endl;
    if (T[i] == 0) {
      int x = -1;
      for (auto ad : adj[val + i]) {
        auto e = E[ad];
        if (e.u != val + i and e.flow) {
          x = e.u;
          break;
        }
      }
      if (x != -1) cout << i+1 << ' ' << x+1 << '\n';
    }
    else if (T[i] == 1) {
      int x = -1;
      for (auto ad : adj[val + i]) {
        auto e = E[ad];
        if (e.u != val + i and e.flow) {
          int y = e.u;
          //cerr << y << endl;
          while (y >= n) {
            int ed = Par[y]+1;
            if (E[Par[y]].flow) ed = Par[y];
            E[ed].flow--;
            y = E[ed].u;
          }
          x = y;
          break;
        }
      }
      if (x != -1) cout << i+1 << ' ' << x+1 << '\n';
    }
    else {
      int x = -1;
      int y = -1;
      for (auto ad : adj[val+i]) {
        auto e = E[ad];
        if (e.v != val + i and !e.flow) {
          if (x == -1) x = e.v;
          else y = e.v;
        }
      }
      cout << i+1 << ' ' << x+1 << '\n';
      cout << i+1 << ' ' << y+1 << '\n';
    }
    //cerr << T[i] << endl;
  }
}