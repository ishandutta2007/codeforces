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
//
#include "bits/stdc++.h"
using namespace std;
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

struct Centroid{
  vector<int> sz,dead;
  vector<vector<int> > edge;
  Centroid(){}
  Centroid(int n):sz(n,1),dead(n,0),edge(n){}
 
  void add_edge(int u,int v){
    edge[u].emplace_back(v);
    edge[v].emplace_back(u);
  }
 
  int dfs(int v,int p){
    sz[v]=1;
    for(int u:edge[v])
      if(u!=p&&!dead[u]) sz[v]+=dfs(u,v);
    return sz[v];
  }
 
  void find(int v,int p,int tmp,vector<int> &cs) {
    int ok=1;
    for (int u:edge[v]){
      if(u==p||dead[u]) continue;
      find(u,v,tmp,cs);
      ok&=(sz[u]<=tmp/2);
    }
    ok&=(tmp-sz[v]<=tmp/2);
    if(ok) cs.push_back(v);
  }
 
  vector<int> build(int r) {
    int tmp=dfs(r,-1);
    vector<int> cs;
    find(r,-1,tmp,cs);
    return cs;
  }
 
  void disable(int v){
    dead[v]=1;
  }
 
  void enable(int v){
    dead[v]=0;
  }
 
  int alive(int v){
    return !dead[v];
  }
};

void solve(){
  int N;
  cin >> N;

  vec edge[N];
  Centroid ctr(N);
  int x,y;
  REP(_,N-1){  
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(y);
    edge[y].emplace_back(x);
    ctr.add_edge(x,y);
  }

  auto g = ctr.build(0);
  if(g.size()==1){
    cout << x+1 SP y+1 << endl;
    cout << x+1 SP y+1 << endl;
    return;
  }

  else{
    for(int to:edge[g[0]]){
      if(to!=g[1]) x = to;
    }
    cout << x+1 SP g[0]+1 << endl;
    cout << x+1 SP g[1]+1 << endl;
  }


}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}