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
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n),cnt(20,0);
  mat cost(20,vec(20,0));
  REP(i,n){
    cin >> a[i]; a[i]--;
    cnt[a[i]]++;
    REP(j,20) if(a[i]!=j) cost[a[i]][j] += cnt[j];
  }
  
  vec dp(1<<20,INF); dp[0] = 0;
  REP(mask,1<<20){
    REP(i,20){
      if(mask&(1<<i)) continue;
      int sum = 0;
      REP(j,20) if(!(mask&(1<<j))&&i!=j) sum += cost[i][j]; 
      dp[mask|(1<<i)] = min(dp[mask|(1<<i)],dp[mask]+sum);
    } 
  }

  cout << dp[(1<<20)-1] << endl;

  return 0;
}