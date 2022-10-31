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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<int> l(n), r(n);
  REP(i,n){
    int s,x;
    cin >> s >> x;
    l[i] = s-x;
    r[i] = s+x;
  }
  
  vec dp(m+10,INF); dp[0] = 0;
  FOR(i,1,m+1){
    int now = dp[i-1];
    //debug(now);
    REP(j,n){
      if(range(i,l[j],r[j]+1)) dp[min(r[j],m)] = min(dp[min(r[j],m)],now);
      else{
        int cost;
        if(i<l[j]) cost = l[j]-i;
        else cost = i-r[j];
        dp[min(r[j]+cost,m)] = min(dp[min(r[j]+cost,m)],now+cost);
      }
    }
  }

  int ans = INF;
  REP(i,m+1) ans = min(ans,dp[i]+m-i); 

  cout << ans << endl;

  return 0;
}