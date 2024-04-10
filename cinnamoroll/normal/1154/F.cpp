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

  int n,m,k;
  cin >> n >> m >> k;

  vec a(n);
  REP(i,n) cin >> a[i];
  
  sort(a.begin(),a.end());
  a.resize(k);

  vec sum(k+1,0);
  REP(i,k) sum[i+1] = sum[i]+a[i];

  vec b(k+1,0);
  REP(_,m){
    int x,y;
    cin >> x >> y;
    if(x > k) continue;
    b[x] = max(b[x],y);
  }

  vec dp(k+1,INF);
  dp[0] = 0;
  REP(i,k){
    FOR(j,i+1,k+1){
      int tmp = sum[j]-sum[i+b[j-i]];
      dp[j] = min(dp[j],dp[i]+tmp);
    }
  }

  cout << dp[k] << endl;

  return 0;
}