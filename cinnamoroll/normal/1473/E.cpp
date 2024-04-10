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
#define parity(i,j) (1&(i>>j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

template <typename T>
struct dijkstra{
  using E = pair<int,T>;
  int N;
  vector<T> dist;
  vector<vector<E>> edge;
  dijkstra(){};
  dijkstra(int N):N(N){
    edge.resize(N);
  }
  void add_edge(int x, int y, T c){
    edge[x].push_back(E(y,c));
  }
  void add_edge2(int x, int y, T c){
    edge[x].push_back(E(y,c));
    edge[y].push_back(E(x,c));
  }
  void build(int s){
    dist.assign(N,LINF);
    dist[s] = 0;
    priority_queue<E,vector<E>,greater<E>> que;
    que.push(E(0,s));
    while(!que.empty()){
      E p = que.top();
      que.pop();
      int v = p.sc;
      if(dist[v] < p.fs) continue;
      for(E to:edge[v]){
        if(dist[to.fs] > dist[v]+to.sc){
          dist[to.fs] = dist[v]+to.sc;
          que.push(E(dist[to.fs],to.fs));
        }
      }
    }
  }
  T get(int no){
    return dist[no];
  }
};

// solveinit()
void solve(){
  int N,M;
  cin >> N >> M;

  dijkstra<int> djk(4*N);
  REP(_,M){
    int x,y,c;
    cin >> x >> y >> c;
    x--; y--;
    REP(i,4) REP(j,4){
      if(parity(i,0) && !parity(j,0)) continue;
      if(parity(i,1) && !parity(j,1)) continue;
      int cost = c;
      if(!parity(i,0) && parity(j,0)) cost -= c;
      if(!parity(i,1) && parity(j,1)) cost += c;
      djk.add_edge(x+i*N,y+j*N,cost);
      djk.add_edge(y+i*N,x+j*N,cost);
    }
  }
  
  djk.build(0);

  FOR(i,1,N){
    cout << djk.get(i+N*3) << " ";
  }
  cout << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}