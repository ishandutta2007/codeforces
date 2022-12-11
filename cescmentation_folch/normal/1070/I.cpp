#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;

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

VVI G;
vector<Edge> E;

void addEdge(int u, int v, int cap){
    Edge e; e.u = u; e.v = v; e.flow = 0; e.cap[0] = cap; e.cap[1] = 0;
    G[u].push_back(E.size());
    G[v].push_back(E.size());
    E.push_back(e);
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<pair<int, int> > a(m);
        G = VVI(n+m+2);
        E.clear();
        int s = n+m, t = s+1;
        VI deg(n,0);
        for (int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v; --u;--v;
            deg[u]++;
            deg[v]++;
            addEdge(u, n+i, 1);
            addEdge(v, n+i, 1);
            addEdge(n+i, t, 1);
        }
        
        bool good = true;
        
        ll add = 0;
        for (int i = 0; i < n and good; ++i){
            if (deg[i] > 2*k) good = false;
            addEdge(s, i, max(0ll, 2*(deg[i]-k)));
            add += 2*max(0ll, (deg[i]-k));
        }
        if (not good){
            for (int i = 0; i < m; ++i) cout << 0 << " ";
            cout << endl;
        }
        else{
            ll f = maxflow(s, t, G, E);
            //cerr << "hola " << add << endl;
            if (f == add){
                int cnt = 0;
                VI col(m, -1);
                for (int i = 0; i < n; ++i){
                    int p = 0;
                    for (int e : G[i]){
                        if (CAP(i, e) == 0 and VEI(i, e) != s){
                            col[E[e].v-n] = cnt;
                            if (p % 2 == 1) cnt++;
                            p++;
                            p %= 2;
                        }
                    }
                }
                for (int i = 0; i < m; ++i){
                    if (col[i] == -1) cout << 1+cnt++ << " ";
                    else cout << col[i]+1 << " ";
                }
                cout << endl;
            }
            else{
                for (int i = 0; i < m; ++i) cout << 0 << " ";
                cout << endl;
            }
        }
    }
    
}