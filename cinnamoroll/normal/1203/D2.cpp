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

  string s,t;
  cin >> s >> t;

  int n = t.size();
  vec L(n+1,0),R(n+1,0);
  int id = 0;
  REP(i,s.size()){
    if(s[i] == t[id]) L[id+1] = i+1, id++;
    if(id == t.size()) break;
  }

  reverse(s.begin(),s.end());
  reverse(t.begin(),t.end());
  id = 0;
  REP(i,s.size()){
    if(s[i] == t[id]) R[id+1] = i+1, id++;
    if(id == t.size()) break;
  }

  int ans = 0;
  REP(i,n+1) ans = max(ans,s.size()-L[i]-R[n-i]);

  cout << ans << endl;

  return 0;
}