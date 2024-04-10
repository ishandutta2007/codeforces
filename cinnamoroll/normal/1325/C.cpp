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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n; 

  vec edge[n];
  map<P,int> mp;
  REP(i,n-1){
    int u,v; cin >> u >> v;
    u--; v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
    mp[P(u,v)] = mp[P(v,u)] = i;
  }

  int cnt = 0;
  vec ans(n,-1);
  REP(i,n){
    if(edge[i].size()>=3){
      for(int no:edge[i]) if(ans[mp[P(i,no)]]==-1) ans[mp[P(i,no)]] = cnt++;
    }
  }

  REP(i,n){
    for(int no:edge[i]) if(ans[mp[P(i,no)]]==-1) ans[mp[P(i,no)]] = cnt++;  
  }

  REP(i,n-1) cout << ans[i] << " ";

  return 0;
}