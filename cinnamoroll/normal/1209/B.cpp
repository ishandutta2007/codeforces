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
  string s;
  cin >> n >> s;

  vector<int> a(n),b(n);
  REP(i,n) cin >> a[i] >> b[i];
  
  int N = 5*4*3*2*6;
  mat c(n,vec(N+10,0));
  REP(i,n){
    int now = s[i]-'0', id = 0;
    REP(_,b[i]) c[i][id] = now, id++;
    now ^= 1;
    while(id<N){
      if(now) REP(_,a[i]) c[i][id] = 1, id++;
      else REP(_,a[i]) c[i][id] = 0, id++;
      now ^= 1;
    }
  }

  // REP(i,n){
  //   REP(j,15) cout << c[i][j] << " ";
  //   cout << endl;
  // }

  int ans = 0;
  REP(i,N){
    int cnt = 0;
    REP(j,n) if(c[j][i]) cnt++;
    ans = max(ans,cnt);
  }

  cout << ans << endl;

  return 0;
}