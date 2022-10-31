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
#define pb push_back
//#define int long long
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

struct SCC{
public:
    int V,cnt = 0;
    mat G,rG,edge;
    vec vs,cmp,used;

  SCC(int node_size) : V(node_size), G(V), rG(V), cmp(V), used(V,0) {}

  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(int u) {
    used[u]++;
    for (int v:G[u]) if(!used[v]) dfs(v);
    vs.push_back(u);
  }

  void dfs(int u, int k) {
    used[u]++;
    cmp[u] = k;
    for (int v:rG[u]) if(!used[v]) dfs(v,k);
  }

  int solve(){
    REP(i,V) if(!used[i]) dfs(i); 
    REP(i,V) used[i] = 0;
    RREP(i,vs.size()) if(!used[vs[i]]) dfs(vs[i],cnt++);
    return cnt;
  }

  void make_graph(){
    edge.resize(cnt);
    REP(i,V){
      for(int v:G[i]){
        if(cmp[i] < cmp[v]) edge[cmp[i]].push_back(cmp[v]);
      }
    }
  }

  void clear(){
    vec().swap(vs);
    vec().swap(used);
    mat().swap(G);
    mat().swap(rG);
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //
  //DP

  int n,m,d;
  cin >> n >> m >> d;

  //i ->i*d+j
  SCC scc(n*d);
  REP(_,m){
    int x,y;
    cin >> x >> y;
    x--;y--;
    REP(j,d){
      if(j != d-1) scc.add_edge(x*d+j,y*d+j+1);
      else scc.add_edge(x*d+j,y*d);
    }
  }

  vector<string> s(n);
  REP(i,n) cin >> s[i];

  //
  int k = scc.solve();
  scc.make_graph();
  scc.clear();

  //
  vec sum(k,0),flag(k,-1);
  REP(i,n){
    REP(j,d){
      //continue
      if(s[i][j] == '0') continue;
      int id = i*d+j;
      //idi
      if(flag[scc.cmp[id]] == i) continue;
      flag[scc.cmp[id]] = i;
      sum[scc.cmp[id]]++;
    }
  }

  //11
  int st = scc.cmp[0];
  vec dp(k,-1e9);
  dp[st] = sum[st];

  FOR(i,st,k){
    //continue
    if(dp[i] < 0) continue;
    for(int to:scc.edge[i]) dp[to] = max(dp[to],dp[i]+sum[to]);
  }

  int ans = 0;
  REP(i,k) ans = max(ans,dp[i]);

  cout << ans << endl;

  return 0;
}