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
#define INF (1LL<<60)
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

typedef vector<vector<P> > Graph;

vector<int> dijkstra(int s, Graph &G){
  priority_queue<P,vector<P>,greater<P>> que;
  int n = G.size();
  vector<int> dist(n);
  dist.assign(n,INF);
  dist[s] = 0;
  que.push(P(0,s));

  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.sc;
    REP(i,G[v].size()){
      if(dist[G[v][i].fs] > dist[v]+G[v][i].sc){
        dist[G[v][i].fs] = dist[v]+G[v][i].sc;
        que.push(P(dist[G[v][i].fs],G[v][i].fs));
      }
    }
  }
  return dist;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  Graph edge(n);
  REP(_,m){
    int x,y;
    cin >> x >> y;
    x--; y--;
    edge[x].emplace_back(P(y,1));
    edge[y].emplace_back(P(x,1));
  }

  vec dist[n];
  REP(i,n) dist[i] = dijkstra(i,edge);

  int s,t,c1,u,v,c2;
  cin >> s >> t >> c1 >> u >> v >> c2;
  s--; t--; u--; v--;

  int mn = INF;
  if(dist[s][t] <= c1 && dist[u][v] <= c2) mn = dist[s][t]+dist[u][v];
  REP(i,n){
    REP(j,n){
      if(dist[s][i]+dist[i][j]+dist[j][t]<=c1 && dist[u][i]+dist[i][j]+dist[j][v] <=c2){
        mn = min(mn,dist[s][i]+dist[i][j]+dist[j][t]+dist[u][i]+dist[j][v]);
      }
      if(dist[s][i]+dist[i][j]+dist[j][t]<=c1 && dist[v][i]+dist[i][j]+dist[j][u] <=c2){
        mn = min(mn,dist[s][i]+dist[i][j]+dist[j][t]+dist[v][i]+dist[j][u]);
      }
    }
  }

  if(mn == INF) cout << -1 << endl;
  else cout << m - mn << endl;

  return 0;
}