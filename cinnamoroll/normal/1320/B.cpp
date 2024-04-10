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

  int n,m;
  cin >> n >> m;

  Graph edge(n);
  vec e[n];
  REP(_,m){
    int x,y;
    cin >> x >> y; x--; y--;
    edge[y].emplace_back(x,1);
    e[x].emplace_back(y);
  }

  int k; cin >> k;
  vector<int> a(k);
  REP(i,k) cin >> a[i], a[i]--;

  vec d = dijkstra(a.back(),edge);
 // REP(i,n) cout << d[i] << " ";
 // cout << endl;

  int mn = 0;
  int now = d[a[0]];
  FOR(i,1,k-1){
    if(d[a[i]]==now-1) now--;
    else mn++, now = d[a[i]];
   // debug(mn);
  }

  int mx = 0;
  now = d[a[0]];
  FOR(i,0,k-1){
    if(d[a[i+1]]!=now-1) mx++, now = d[a[i+1]];
    else{
      now--;
      int cnt = 0;
      for(int to:e[a[i]]){
        if(d[to]==now) cnt++;
      }
      if(cnt>1) mx++;
      //debug(cnt);
    }
    //debug(mx); debug(now);
  }

  cout << mn SP mx << endl;

  return 0;
}