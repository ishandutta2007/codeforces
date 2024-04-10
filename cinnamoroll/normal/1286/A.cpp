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
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void chmin(int &x, int y){
  if(x > y) x = y;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  vec flag(n+1,0);
  REP(i,n) cin >> a[i], flag[a[i]]++;

  int odd = 0, eve = 0;
  FOR(i,1,n+1) if(!flag[i]) (i%2?odd:eve)++;
  
  int dp[2][111][111][111];
  REP(i,111) REP(j,111) REP(k,111) dp[0][i][j][k] = dp[1][i][j][k] = INF;
  dp[0][0][0][0] = dp[1][0][0][0] = 0;

  REP(i,n){
    REP(j,eve+1){
      REP(k,odd+1){
        if(a[i]){
          dp[a[i]%2][i+1][j][k] = min(dp[0][i][j][k]+a[i]%2,dp[1][i][j][k]+(a[i]%2==0));
          continue;
        }
        chmin(dp[0][i+1][j+1][k],dp[0][i][j][k]);
        chmin(dp[0][i+1][j+1][k],dp[1][i][j][k]+1);
        chmin(dp[1][i+1][j][k+1],dp[0][i][j][k]+1);
        chmin(dp[1][i+1][j][k+1],dp[1][i][j][k]);
      }
    }
  }

  cout << min(dp[0][n][eve][odd],dp[1][n][eve][odd]) << endl;

  return 0;
}