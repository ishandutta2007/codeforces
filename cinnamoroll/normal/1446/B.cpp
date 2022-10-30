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
#define int short
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

int dp[5001][5001][2][2];

void solve(){
  int N,M;
  string S,T;
  cin >> N >> M >> S >> T;

  REP(i,N) REP(j,M) REP(k,2) REP(l,2){
    if(S[i]==T[j] && k && l) dp[i][j][1][1] = 2;
    else dp[i][j][k][l] = -10101;
  }

  S += "#"; T += "%";

  int ans = 0;
  REP(i,N) REP(j,M) REP(k,2) REP(l,2){
    chmax(ans,dp[i][j][k][l]);
    //cout << i SP j SP k SP l SP dp[i][j][k][l] << endl;
    if(S[i+1]==T[j] && !l) chmax(dp[i+1][j][1][1],dp[i][j][k][l]+3);
    else chmax(dp[i+1][j][0][l],dp[i][j][k][l]-1);

    if(S[i]==T[j+1] && !k) chmax(dp[i][j+1][1][1],dp[i][j][k][l]+3);
    else chmax(dp[i][j+1][k][0],dp[i][j][k][l]-1);    
  }

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