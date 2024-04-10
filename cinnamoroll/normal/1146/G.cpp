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

  int n,h,m;
  cin >> n >> h >> m;

  max_flow mf(n*(h+2)+m+2);
  int s = n*(h+2)+m, t = n*(h+2)+m+1;

  REP(i,n) mf.add_edge(s,i*(h+2),INF), mf.add_edge((i+1)*(h+2)-1,t,INF);

  REP(i,n){
    REP(j,h+1){
      mf.add_edge(i*(h+2)+j,i*(h+2)+j+1,h*h-j*j);
    }
  }

  int tmp = (h+2)*n;
  REP(i,m){
    int l,r,x,c;
    cin >> l >> r >> x >> c;
    mf.add_edge(tmp+i,t,c);
    FOR(j,l-1,r) mf.add_edge(j*(h+2)+x+1,tmp+i,INF);
  }

  cout << h*h*n - mf.run(s,t) << endl;

  return 0;
}