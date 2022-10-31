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
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void solve(){
  int N,Z,X,Y,D;
  cin >> N >> X >> Y >> Z >> D;

  vector<int> a(N);
  REP(i,N) cin >> a[i];
  
  vector<int> b(N,0); // i->N->imin
  b[N-1] = a.back()*X+Z;
  RREP(i,N-1){
    b[i] = 2*D + min({Y+X,(a[i]+2)*X});
    b[i] += b[i+1];
  }

  // REP(i,N) cout << b[i] << " ";
  // cout << endl;

  
  vec dp(N+2,LINF); dp[0] = 0;
  REP(i,N){
    int c = a[i]*X+Z; // 
    int d = min(Y+X,(a[i]+2)*X); // 
    chmin(dp[i+1],dp[i]+c+D);
    chmin(dp[i+1],dp[i]+d+3*D);
    if(i!=N-1){
      int e = min(Y+X,(a[i+1]+2)*X); // 
      chmin(dp[i+2],dp[i]+d+e+4*D);
    }
  }

  // REP(i,N+1) cout << dp[i] << " ";
  // cout << endl;
  
  int ans = dp[N]-D;
  REP(i,N) chmin(ans,dp[i]+b[i]);

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