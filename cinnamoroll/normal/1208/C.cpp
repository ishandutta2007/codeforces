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

  mat ans(n,vec(n)); int x = 0;
  // REP(i,n){
  //   REP(j,n) ans[i][j] = x, x++;
  // }

  // RREP(i,n/2){
  //   RREP(j,n) ans[i*2+1][j] = x, x++;//ans[i*2+1][j] = ans[i*2][j]^(n*n-1);
  // }

  
  REP(k,n/4){
    REP(i,n){
      REP(j,4){
        ans[i][k*4+j] = x, x++;
      }
    }
  }

  // REP(i,n){
  //   int z = 0 ,y = 0;
  //   REP(j,n){
  //     z ^= ans[i][j]; y ^= ans[j][i];
  //   }
  //   assert(z==0&&y==0);
  // }

  REP(i,n){
    REP(j,n) cout << ans[i][j] << " ";
    cout << "\n";
  }

  return 0;
}