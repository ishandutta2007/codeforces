// warm heart, wagging tail,and a smile just for you!
//                                                                        
//                                                                   
//                                                                
//                                                   
//                                      
//                               
//                             
//                           
//                         
//                       
//                     
//                 
//     
//   
// 
// 
// 
// 
//   
//         
//                                                        
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define D double
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

struct LowLink {
  set<pair<int, int>> bridge;
  vector<int> articulation, ord, low;
  vector<bool> used;
  vector<vector<int>> g;
  int n, k = 0;
  LowLink(const vector<vector<int>> &g) : g(g) {
    n = g.size();
    ord.resize(n, 0);
    low.resize(n, 0);
    used.resize(n, false);
  }
  void dfs(int u, int prev) {
    used[u] = true;
    ord[u] = k++;
    low[u] = ord[u];
    bool is_articulation = false;
    int cnt = 0;
    for (auto v : g[u]) if (v != prev) {
      if (!used[v]) {
        cnt ++;
        dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > ord[u]) {
          bridge.emplace(min(u, v), max(u, v));
        } 
        if (prev != -1 && low[v] >= ord[u]) {
          is_articulation = true;
        }
      } else {
        low[u] = min(low[u], ord[v]);
      }
    }
    if (prev == -1 && cnt > 1) is_articulation = true;
    if (is_articulation) articulation.push_back(u);
  }
};

struct TwoEdgeConnectedComponent {
  int n;
  vector<vector<int>> g, tree;
  vector<int> cmp,sz;
  TwoEdgeConnectedComponent(){};
  TwoEdgeConnectedComponent(const vector<vector<int>> &g) : g(g) {
    n = (int) g.size();
    cmp.assign(n, -1);
  }
  void build() {
    LowLink lnk(g);
    lnk.dfs(0, -1);
    int k = 0;
    function<void (int, int)> dfs = [&](int u, int prev) {
      cmp[u] = k;
      for (auto v : g[u]) if (cmp[v] == -1 && lnk.bridge.count({min(u, v), max(u, v)}) == 0) {
        dfs(v, u);
      }
    };
    for (int i = 0; i < n; i ++) if (cmp[i] == -1) {
      dfs(i, -1);
      k ++;
    }
    tree.resize(k);
    sz.assign(k,0);
    for(int i = 0; i < n; i++) sz[cmp[i]]++;
    for (auto e : lnk.bridge) {
      tree[cmp[e.first]].push_back(cmp[e.second]);
      tree[cmp[e.second]].push_back(cmp[e.first]);
    }
  }
};

int mx = 0;
vec b(2e5+10);
void dfs(int no, int par, int now, mat &edge){
  mx = max(mx,now);
  for(int to:edge[no]){
    if(to==par) continue;
    now += b[to];
    dfs(to,no,now,edge);
    now -= b[to];
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vec a(n);
  REP(i,n) cin >> a[i];

  mat edge(n);
  REP(_,m){
    int x,y;
    cin >> x >> y; x--; y--;
    edge[x].push_back(y);
    edge[y].push_back(x);
  }

  int s; cin >> s; s--;

  TwoEdgeConnectedComponent tecc(edge);
  tecc.build();

  REP(i,n) if(tecc.sz[tecc.cmp[i]] > 1){
    edge[i].push_back(s);
    edge[s].push_back(i);
  }

  TwoEdgeConnectedComponent tecc2(edge);
  tecc2.build();

  int ans = 0;
  REP(i,n){
    if(tecc2.cmp[i] == tecc2.cmp[s]) ans += a[i];
    b[tecc2.cmp[i]] = a[i];
  }

  dfs(tecc2.cmp[s],-1,0,tecc2.tree);

  cout << ans + mx << endl;

  return 0;
}