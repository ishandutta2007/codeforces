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
  //
  //
  //DP

  int n,k;
  cin >> n >> k;

  vec a(n);
  REP(i,n) cin >> a[i];
  
  sort(a.begin(),a.end());

  mat dp(n+1,vec(k+1,0));
  REP(i,n){
    int id = lower_bound(a.begin(),a.end(),a[i]-5) - a.begin();
    int cnt = i-id+1;
    REP(j,k){
      dp[i+1][j+1] = max(dp[i+1][j+1],dp[id][j]+cnt);
      dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
    }
  }

  cout << dp[n][k] << endl;

  return 0;
}