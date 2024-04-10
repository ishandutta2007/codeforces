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

struct max_flow{
  public:
  struct edge {int to,cap,rev;};
  int V;
  vector<vector<edge>> G;
  vector<int> level,iter;

  max_flow(int v){
    V = v; G.resize(v);
  }

  void add_edge(int from, int to, int cap){
    G[from].pb((edge){to,cap,G[to].size()});
    G[to].pb((edge){from,0,G[from].size()-1});
  }

  void bfs(int s){
    level.assign(V,-1);
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
      int v = que.front();
      que.pop();
      REP(i,G[v].size()){
        edge &e = G[v][i];
        if(e.cap > 0 && level[e.to] < 0){
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }

  int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i = iter[v]; i < G[v].size(); i++){
      edge &e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]){
        int d = dfs(e.to,t,min(f,e.cap));
        if(d > 0){
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  int run(int s, int t){
    int flow = 0;
    while(1){
      bfs(s);
      if(level[t] < 0) return flow;
      iter.assign(V,0);
      int tmp;
      while((tmp = dfs(s,t,INF)) > 0){
        flow += tmp;
      }
    }
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  
  int n,m;
  cin >> n >> m;

  vector<int> p(n);
  REP(i,n) cin >> p[i];
  
  vector<int> c(n);
  REP(i,n) cin >> c[i];
  
  int d;
  cin >> d;

  vector<int> k(d), flag(n,0);
  REP(i,d){
    cin >> k[i];
    k[i]--;
    flag[k[i]]++;
  }

  max_flow mf(10100);

  REP(i,m) mf.add_edge(0,i+1,1);
  mf.add_edge(5001,10010,1);
  REP(i,n) if(flag[i] == 0) mf.add_edge(c[i],p[i]+5001,1);
  
  vec ans(d+1,0);
  RREP(i,d){
    ans[i] = ans[i+1];
    while(mf.run(0,10010)){
      ans[i]++;
      mf.add_edge(5001+ans[i],10010,1);
    }
    mf.add_edge(c[k[i]],p[k[i]]+5001,1);
  }

  REP(i,d) cout << ans[i] << endl;

  return 0;
}