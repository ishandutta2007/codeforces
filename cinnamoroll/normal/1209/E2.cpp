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
#define INF (1<<30)
#define D double
#define fs first
#define sc second
//#define int long long
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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  REP(_,t){
    int n,m;
    cin >> n >> m;

    vector<P> mx(2000,P(0,0));
    REP(i,2000) mx[i].sc = i; 
    vector<vector<int>> a(n,vector<int>(2000,0));
    REP(i,n) REP(j,m) cin >> a[i][j], mx[j].fs = max(mx[j].fs,a[i][j]);
    
    sort(mx.rbegin(),mx.rend());
    m = min(n,m);

    vec dp(1<<n,-INF); dp[0] = 0;
    REP(i,m){
      int id = mx[i].sc;
      vec tmp(1<<n,-INF), now(1<<n,-INF);
      REP(j,n){
        REP(mask,1<<n){
          int cur = 0;
          REP(k,n) if(mask&(1<<k)) cur += a[(j+k)%n][id];
          tmp[mask] = max(tmp[mask],cur);
        }
      }
      REP(mask,1<<n){
        RREP(i,mask+1){
          i &= mask;
          now[mask] = max(now[mask],dp[i]+tmp[mask^i]);
        }
      }
      dp=now;
    }
    cout << dp[(1<<n)-1] << "\n";
  }

  return 0;
}