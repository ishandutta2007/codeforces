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
  string s,t;
  cin >> n >> s >> t;

  vector<string> tmp = {"abc","acb","bac","bca","cab","cba"};
  string res;
  for(string u:tmp){  
    REP(_,n) res += u;
    bool flag = true;
    REP(i,3*n-1) if(res.substr(i,2) == s || res.substr(i,2) == t) flag = false; 
    if(flag) break;
    res.clear();
    REP(i,3) REP(_,n) res+=u[i];
    flag = true;
    REP(i,3*n-1) if(res.substr(i,2) == s || res.substr(i,2) == t) flag = false; 
    if(flag) break;
    res.clear();
  }

  cout << "Yes" << endl;
  cout << res << endl;

  return 0;
}