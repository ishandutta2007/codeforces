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

  int t;
  cin >> t;

  REP(_,t){
    int n;
    string s;
    cin >> n >> s;
    REP(i,9){
      string u,v;
      int l = n,r = -1;
      vec col(n,0);
      REP(j,n){
        if(s[j]-'0' < i) u += s[j] ,r = j, col[j] = 1;
        else if(s[j]-'0' > i) v += s[j], l = min(l,j), col[j] = 2;
      }
      bool flag = true;
      //cout << l SP r << endl;
      REP(j,n){
        if(s[j]-'0' != i) continue;
        if(j < l) col[j] = 2;
        else if(r < j) col[j] = 1;
        else flag = false;
      }
      //cout << u SP v << endl;
      u += v;
      REP(j,u.size()-1) if(u[j] > u[j+1]) {flag = false; break;}
      if(flag){
        //debug(i);
        REP(j,n){
          cout << col[j];
        }          cout << "\n";
          goto out;
      }
    }
    cout << '-' << "\n";
    out:;
  }

  return 0;
}