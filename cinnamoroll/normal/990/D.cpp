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

  int n,a,b;
  cin >> n >> a >> b;
  
  mat e(n,vec(n,0));
  
  if((a!=1&&b!=1) || (range(n,2,4)&&a==1&&b==1)){
    cout << "NO" << endl;
    return 0;
  }
  if(a == 1){
    REP(i,n-b) e[i][i+1] = e[i+1][i] = 1;
    cout << "YES" << endl;
    REP(i,n){
      REP(j,n) cout << (i==j?0:(e[i][j]^1));
      cout << endl;
    }
  }
  else if(b == 1){
    REP(i,n-a) e[i][i+1] = e[i+1][i] = 1;
    cout << "YES" << endl;
    REP(i,n){
      REP(j,n) cout << e[i][j];
      cout << endl;
    }
  }
  

  return 0;
}