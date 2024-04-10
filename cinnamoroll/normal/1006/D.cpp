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
  
  int ans = 0;
  REP(i,n/2){
    vec a(26,0),b(26,0);
    a[s[i]-'a']++; b[t[i]-'a']++;
    a[s[n-1-i]-'a']++; b[t[n-1-i]-'a']++;
    bool flag = false;
    REP(j,26) if(b[j]==2) flag = true;
    if(flag){
      REP(j,26) if(a[j]==2) flag = false;
      if(flag) ans++;
    }
    else{
      REP(j,26) if(!a[j]&&b[j]) ans++;
    }
  }

  if(n%2) if(s[n/2]!=t[n/2]) ans++;

  cout << ans << endl;

  return 0;
}