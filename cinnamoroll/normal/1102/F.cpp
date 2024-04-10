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
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1<<30)
#define D double
#define fs first
#define sc second
//#define int long long
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<vector<int>> a(n,vector<int>(m));
  REP(i,n) REP(j,m) cin >> a[i][j];
  
  mat b(n,vec(n));
  mat c(n,vec(n));
  REP(i,n){
    REP(j,n){
      int mn = INF;
      REP(k,m) mn = min(mn,abs(a[i][k]-a[j][k]));
      b[i][j] = mn;
      mn = INF;
      REP(k,m-1) mn = min(mn,abs(a[i][k]-a[j][k+1]));
      c[i][j] = mn;
    }
  }

  int ans = 0;
  REP(i,n){
    mat dp(1<<n,vec(n,0));
    dp[1<<i][i] = INF;
    REP(j,1<<n){
      REP(k,n){
        REP(l,n){
          if(j&(1<<l)) continue;
          dp[j|(1<<l)][l] = max(dp[j|(1<<l)][l],min(dp[j][k],b[k][l]));
        }
      }
    }
    REP(j,n) ans = max(ans,min(dp[(1<<n)-1][j],c[j][i]));
  }

  cout << ans << endl;

  return 0;
}