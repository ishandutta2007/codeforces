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
#define MOD 1000000007
//#define MOD 998244353
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
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x,y,z;
  cin >> x >> y >> z;
  int n = x+y+z;
  vec a(n+1);
  int k;
  REP(i,x) cin >> k, a[k] = 0;
  REP(i,y) cin >> k, a[k] = 1;
  REP(i,z) cin >> k, a[k] = 2;

  mat dp(3,vec(n+2,0));
  REP(i,n){
    dp[0][i+1] = dp[0][i] + (a[i+1]!=0);
    dp[1][i+1] = min(dp[1][i],dp[0][i]) + (a[i+1]!=1);
    dp[2][i+1] = min({dp[2][i],dp[1][i],dp[0][i]}) + (a[i+1]!=2);
  }

  cout << min({dp[0][n],dp[1][n],dp[2][n]}) << endl;

  return 0;
}