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
#define MOD 1000000007
//#define MOD 998244353
#define INF (1LL<<30)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
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

vec used;
int dfs(int no, int ng, mat &edge, int par){
  int res = 0; used[no]++;
  for(int to:edge[no]){
    if(used[to]) continue;
    if(to==par) continue;
    if(to==ng) continue;
    int tmp = dfs(to,ng,edge,no)+1;
    res += tmp;
  }
  return res;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n,m,a,b;
    cin >> n >> m >>a >> b; a--,b--;

    //max_flow mf(n);
    mat edge(n);
    REP(_,m){
      int x,y;
      cin >> x >> y; x--; y--;
     // mf.add_edge(x,y,1);
     // mf.add_edge(y,x,1);
      edge[x].push_back(y);
      edge[y].push_back(x);
    }

   // if(mf.run(a,b)>1) cout << 0 << "\n";
    //else{
      used.assign(n,0);
      int s = (n-dfs(a,b,edge,-1)-2);
      used.assign(n,0);
      cout << s*(n-dfs(b,a,edge,-1)-2) << "\n";
   // }

  }

  return 0;
}