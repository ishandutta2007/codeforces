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

int dp[202][202][202];

void solve(){
  int x,y,z;
  cin >> x >> y >> z;

  vector<int> a(x);
  REP(i,x) cin >> a[i];
  
  vector<int> b(y);
  REP(i,y) cin >> b[i];
  
  vector<int> c(z);
  REP(i,z) cin >> c[i];
  
  sort(a.rbegin(),a.rend());
  sort(b.rbegin(),b.rend());
  sort(c.rbegin(),c.rend());
  
  REP(i,x+1) REP(j,y+1) REP(k,z+1){
    if(i<x&&j<y) chmax(dp[i+1][j+1][k],dp[i][j][k]+a[i]*b[j]);
    if(i<x&&k<z) chmax(dp[i+1][j][k+1],dp[i][j][k]+a[i]*c[k]);
    if(k<z&&j<y) chmax(dp[i][j+1][k+1],dp[i][j][k]+c[k]*b[j]);
  }
  
  int ans = 0;
  REP(i,x+1) REP(j,y+1) REP(k,z+1) chmax(ans,dp[i][j][k]);

  cout << ans << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}