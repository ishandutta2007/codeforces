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
  int N,K;
  cin >> N >> K;

  vector<int> l(N),r(N),a(N);
  REP(i,N) cin >> l[i] >> r[i] >> a[i];
  
  vec dp(N+1,LINF); // dp[i] : imin
  dp[0] = 0;
  int ans = LINF;
  REP(i,N){
    if(dp[i]==LINF) continue;
    int cnt = 0, now = K;
    FOR(j,i,N){
      if((r[j]-l[j])*K+now < a[j]) break;
      cnt += a[j];
      if((r[j]-l[j]-1)*K+now >= a[j] && l[j]<r[j]) chmin(dp[j+1],dp[i]+(cnt+K-1)/K*K);
      if(j+1<N && r[j]<l[j+1]) chmin(dp[j+1],dp[i]+(cnt+K-1)/K*K);
      if(j+1==N) chmin(ans,dp[i]+cnt);
      now = K-cnt%K;
      if(now==K) now = 0;
    }
    //REP(i,N) cout << dp[i] << " "; cout << endl;
  }

  if(ans==LINF) ans = -1;
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