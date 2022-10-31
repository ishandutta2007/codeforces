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
#define INF (1LL<<60)
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
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
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

  int n,m,k;
  cin >> n >> m >> k;

  vector<int> a(k);
  REP(i,k) cin >> a[i], a[i]--;
  
  Graph G(n);
  REP(i,m){
    int x,y;
    cin >> x >> y; x--; y--;
    G[x].emplace_back(y,1);
    G[y].emplace_back(x,1);
  }

  vec s = dijkstra(0,G), t = dijkstra(n-1,G);
  auto comp = [&](int x, int y){
    return s[x] < s[y];
  };
  sort(a.begin(),a.end(),comp);
  int ans2 = s[n-1];
  vec u(k),v(k);
  REP(i,k){
    u[i] = s[a[i]];
    v[i] = t[a[i]];
  }

  int ans = 0;
  RREP(i,k-1) chmax(v[i],v[i+1]);
  REP(i,k-1) chmax(ans,u[i]+v[i+1]+1);

  cout << min(ans,ans2) << endl;

  return 0;
}