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
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,x;
  string s;
  cin >> n >> x >> s;

  mat next(n+1,vec(26,INF));
  RREP(i,n){
    REP(j,26) next[i][j] = next[i+1][j];
    next[i][s[i]-'a'] = i;
  }

  int dp[111][111] = {};
  dp[0][0] = 1;
  REP(i,n){
    REP(j,n){
      REP(k,26){
        if (next[i][k] >= n) continue;
        dp[next[i][k] + 1][j+1] += dp[i][j];
      }
    }
  }

  int ans = 0;
  RREP(i,n+1){
    int sum = 0;
    REP(j,n+1) sum += dp[j][i];
    //debug(sum);
    ans += (n-i)*min(sum,x);
    x -= sum;
    if(x <= 0) break;
  }

  if(x <= 0) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}