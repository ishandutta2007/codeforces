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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vec a(n);
  REP(i,n) cin >> a[i];

  mat dp(2);
  dp[0].assign(n,INF);  //
  dp[1].assign(n,-INF); //

  dp[0][0] = -INF; dp[1][0] = INF;

  REP(i,n-1){
    // a[i]
    if(a[i] > a[i+1]) dp[0][i+1] = dp[0][i];
    // a[i+1]
    if(dp[1][i] > a[i+1]) dp[0][i+1] = min(dp[0][i+1],a[i]);
    // INF

    if(a[i] < a[i+1]) dp[1][i+1] = dp[1][i];
    if(dp[0][i] < a[i+1]) dp[1][i+1] = max(dp[1][i+1],a[i]);

    // 
    if(dp[0][i+1] == INF && dp[1][i+1] == -INF){
      cout << "NO" << endl;
      return 0;
		}
  }

  cout << "YES" << endl;
  int tmp = 1;
  if(dp[0][n-1] == INF) tmp = 0;

  vec ans(n);
  RFOR(i,1,n){
    ans[i] = tmp;
    if(tmp == 0 && dp[1][i] != dp[1][i-1]) tmp = 1;
    else if(tmp == 1 && dp[0][i] != dp[0][i-1]) tmp = 0;
  }
  ans[0] = tmp;

  REP(i,n) cout << ans[i] << " ";
  cout << endl;

  return 0;
}