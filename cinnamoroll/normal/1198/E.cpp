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
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<40)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
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
    G[from].push_back((edge){to,cap,G[to].size()});
    G[to].push_back((edge){from,0,G[from].size()-1});
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
// INF

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<P> xx(m),yy(m);
  vec x,y;
  REP(i,m){
    cin >> xx[i].fs >> yy[i].fs >> xx[i].sc >> yy[i].sc;
    xx[i].sc++; yy[i].sc++;
    x.emplace_back(xx[i].fs);
    x.emplace_back(xx[i].sc);
    y.emplace_back(yy[i].fs);
    y.emplace_back(yy[i].sc);
  }

  sort(x.begin(),x.end());
  sort(y.begin(),y.end());

  max_flow mf(260);
  int s = 251, t = 252;
  
  REP(i,2*m-1){
    mf.add_edge(s,i,x[i+1]-x[i]);
    mf.add_edge(i+100,t,y[i+1]-y[i]);

    REP(j,m) if(xx[j].fs <= x[i] && x[i+1] <= xx[j].sc) mf.add_edge(i,j+200,INF);
    REP(j,m) if(yy[j].fs <= y[i] && y[i+1] <= yy[j].sc) mf.add_edge(j+200,i+100,INF);
  }

  cout << mf.run(s,t) << endl;

  return 0;
}