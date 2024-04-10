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
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();

  vec mn(n,INF);

  REP(i,n){
    FOR(j,1,n){
      if(i+j*2 >= n) break;
      if(s[i] == s[i+j] && s[i] == s[i+2*j]){
        mn[i] = min(mn[i],i+2*j);
        break;
      }
    }
  }

  vec MN(n+1,INF);
  RREP(i,n) MN[i] = min(MN[i+1],mn[i]);
 // REP(i,n) cout << mn[i] SP MN[i] << endl;

  int ans = 0;
  REP(i,n){
    if(mn[i] == INF && MN[i] != INF) ans += n-MN[i];
    else if(mn[i] != INF) ans += n-min(mn[i],MN[i]);
   // debug(ans);
  }

  cout << ans << endl;

  return 0;
}