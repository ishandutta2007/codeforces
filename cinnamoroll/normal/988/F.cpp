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
  
  int v,n,m;
  cin >> v >> n >> m;
  
  vector<P> a(n);
  REP(i,n) cin >> a[i].fs >> a[i].sc;
  
  vector<P> b(m);
  REP(i,m) cin >> b[i].fs >> b[i].sc;
  
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  b.emplace_back(P(0,0));

  int x = 2*n+m;
  vector<P> id;
  REP(i,n){
    id.emplace_back(P(a[i].fs,i+2000));
    id.emplace_back(P(a[i].sc,i+4000)); 
  }
  REP(i,m) id.emplace_back(P(b[i].fs,i));

  sort(id.begin(),id.end());

  int dp[2][2222];
  REP(i,m+1) dp[0][i] = INF;
  dp[0][m] = 0;

  int now = 0;
  REP(i,x){
    REP(j,m+1) dp[(i+1)&1][j] = INF;
    P k = id[i];
    if(k.sc<2000){
      REP(j,m+1){
        dp[(i+1)&1][j] = min(dp[(i+1)&1][j],dp[i&1][j]+(k.fs-now)*b[j].sc);
        dp[(i+1)&1][k.sc] = min(dp[(i+1)&1][k.sc],dp[(i+1)&1][j]);
      }
    }
    else if(k.sc < 4000){
      k.sc -= 2000;
      REP(j,m){
        dp[(i+1)&1][j] = dp[i&1][j]+(k.fs-now)*b[j].sc;
      }
    }
    else{
      k.sc -= 4000;
      REP(j,m){
        dp[(i+1)&1][j] = dp[i&1][j]+(k.fs-now)*b[j].sc;
        dp[(i+1)&1][m] = min(dp[(i+1)&1][m],dp[(i+1)&1][j]);
      }
    }
    now = k.fs;
  }

  int ans = INF;
  REP(i,m+1) ans = min(ans,dp[x&1][i]);

  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl; 

  return 0;
}