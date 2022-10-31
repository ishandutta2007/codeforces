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

  vector<string> s(3);
  REP(i,3) cin >> s[i];

  int a[3][9] = {};
  
  REP(i,3){
    if(s[i][1] == 'm') a[0][s[i][0]-'1']++;
    if(s[i][1] == 'p') a[1][s[i][0]-'1']++;
    if(s[i][1] == 's') a[2][s[i][0]-'1']++;
  }

  int ans = 3;
  REP(i,3){
    REP(j,9) ans = min(ans,3-a[i][j]);
    REP(j,7){
      int cnt = 0;
      REP(k,3) if(a[i][j+k]) cnt++;
      ans = min(ans,3-cnt);
    }
  }

  cout << ans << endl;

  return 0;
}