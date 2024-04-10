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

int dp[2][501][501];

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m,b,mod;
  cin >> n >> m >> b >> mod;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  dp[0][0][0] = 1;
  REP(i,n){
    REP(j,501) REP(k,501) dp[(i+1)&1][j][k] = 0;
    REP(j,501) REP(k,501) dp[(i+1)&1][j][k] = dp[i&1][j][k];
    REP(j,500) REP(k,501){
      if(k+a[i]>500) break;
      dp[(i+1)&1][j+1][k+a[i]] += dp[(i+1)&1][j][k];
      dp[(i+1)&1][j+1][k+a[i]] %= mod;
    }
  }

  int ans = 0;
  REP(i,b+1){
    ans += dp[n&1][m][i];
    ans %= mod;
  }

  cout << ans << endl;

  return 0;
}