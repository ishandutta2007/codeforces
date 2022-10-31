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

  int n,q;
  cin >> n >> q;

  vec L[n+5],R[n+5];
  REP(_,q){
    int a,b,c;
    cin >> a >> b >> c;
    L[a].push_back(c);
    R[b+1].push_back(c);
  }

  vec dp(n+1,0),flag(n+1,0);
  dp[0] = 1;

  FOR(i,1,n+1){
    for(int x:R[i]) FOR(j,x,n+1) dp[j] = (dp[j]-dp[j-x])%MOD;
    for(int x:L[i]) RREP(j,n+1-x) dp[x+j] = (dp[x+j]+dp[j])%MOD;
    FOR(j,1,n+1) if(dp[j]) flag[j]++;
  }

  vec ans;
  REP(i,n) if(flag[i+1]) ans.push_back(i+1);
  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i] << " ";
  cout << endl;

  return 0;
}