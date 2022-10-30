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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
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

  int n;
  cin >> n;

  vector<int> a[n],b[n],c[n];
  REP(i,n){
    int x;
    cin >> x;
    REP(_,3){
      a[i].emplace_back(-INF);
      b[i].emplace_back(-INF);
      c[i].emplace_back(-INF);
    }
    REP(_,x){
      int s,t;
      cin >> s >> t;
      if(s == 1) a[i].emplace_back(t);
      else if(s == 2) b[i].emplace_back(t);
      else c[i].emplace_back(t);
    }
    sort(a[i].begin(),a[i].end());
    sort(b[i].begin(),b[i].end());
    sort(c[i].begin(),c[i].end());
  }

  mat dp(n+1,vec(10,-INF));
  dp[0][0] = 0;
  REP(i,n){
    //0
    REP(j,10) dp[i+1][j] = dp[i][j];
    
    //1
    int tmp = max({a[i].back(),b[i].back(),c[i].back()});
    REP(j,9) dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+tmp);
    dp[i+1][0] = max(dp[i+1][0],dp[i][9]+tmp*2);

    //2
    int sz = a[i].size();
    tmp = max(a[i].back()+b[i].back(),a[i][sz-1] + a[i][sz-2]);
    int tmp2 = max(a[i].back()+b[i].back()+max(a[i].back(),b[i].back()),a[i][sz-1]*2 + a[i][sz-2]);
    REP(j,8) dp[i+1][j+2] = max(dp[i+1][j+2],dp[i][j]+tmp);
    REP(j,2) dp[i+1][j] = max(dp[i+1][j],dp[i][8+j]+tmp2);

    //3
    tmp = a[i][sz-1] + a[i][sz-2] +a[i][sz-3];
    REP(j,7) dp[i+1][j+3] = max(dp[i+1][j+3],dp[i][j]+tmp);
    REP(j,3) dp[i+1][j] = max(dp[i+1][j],dp[i][7+j]+tmp+a[i].back());
  }

  int ans = 0;
  REP(i,10) ans = max(ans,dp[n][i]);

  cout << ans << endl;

  return 0;
}