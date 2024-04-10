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
const double EPS = 1e-9;
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

  int n;
  cin >> n;

  vector<P> a(n);
  REP(i,n) cin >> a[i].fs, a[i].sc = i;
    int mx = -INF, mn = INF;
    REP(i,n) mx = max(mx,a[i].fs), mn = min(mn,a[i].fs);
  if(n<6){

    cout << mx-mn SP 1 << endl;
    REP(i,n) cout << 1 << " ";
    cout << endl;
    return 0;
  }
  
  sort(a.begin(),a.end());
  vec ans(n);

  mat dp(3,vec(n,0));
  FOR(i,2,n-3){
    dp[0][i+1] = max(dp[0][i],dp[1][i]);
    dp[1][i+1] = dp[2][i];
    dp[2][i+1] = dp[0][i]+a[i+1].fs-a[i].fs;
  }

  //REP(i,n) cout << dp[0][i] SP dp[1][i] SP dp[2][i] << endl;

  vec list;
  int id, mxe = -INF;
  REP(i,3) if(dp[i][n-3] > mxe) mxe = dp[i][n-3], id = i;

  RFOR(i,2,n-3){
    if(id==0){
      if(dp[0][i+1] == dp[1][i]) id++;
    }
    else if(id==1) id++;
    else id = 0,list.push_back(i);
  }

  sort(list.begin(),list.end());
  int now = 0;
  REP(i,n){
    if(now < list.size() && list[now]==i-1) now++;
    ans[a[i].sc] = now+1;
  }

  cout << mx - mn - mxe SP now+1 << endl;
  REP(i,n) cout << ans[i] << " ";

  return 0;
}