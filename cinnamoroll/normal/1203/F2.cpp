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

  int n,r;
  cin >> n >> r;

  vector<P> a,b;
  REP(_,n){
    int x,y;
    cin >> x >> y;
    if(y >= 0) a.push_back(P(x,y));
    else b.push_back(P(x,-y));
  }

  sort(a.begin(),a.end());

  int ans = 0;
  REP(i,a.size()){
    if(r >= a[i].fs) ans++, r += a[i].sc;
  }

  int m = b.size();
  auto comp = [&](P x, P y){return y.fs+x.sc<x.fs+y.sc;};

  sort(b.begin(),b.end(),comp);
  mat dp(m+1,vec(r+1,-INF));
  dp[0][r] = 0;

  REP(i,m){
    REP(j,r+1){
      dp[i+1][j] = dp[i][j];
      if(j >= b[i].fs && j-b[i].sc>=0) dp[i+1][j-b[i].sc] = max(dp[i+1][j-b[i].sc],dp[i][j]+1);
    }
  }

  int mx = 0;
  REP(i,r+1) mx = max(mx,dp[m][i]);

  //if(ans+mx == n) cout << "YES" << endl;
  //else cout << "NO" << endl;
  
  cout << ans+mx << endl;

  return 0;
}