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
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
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

  vec a(3);
  REP(i,3) cin >> a[i];

  int tmp = min({a[0]/3,a[1]/2,a[2]/2});
  int ans = tmp*7;
  a[0] -= tmp*3;
  a[1] -= tmp*2;
  a[2] -= tmp*2;

  int food[] = {0,1,2,0,2,1,0};
  int cnt = 0;
  REP(i,7){
    vec cur(3,0);
    int cnt2 = 0;
    REP(j,7){
      if(cur[food[(i+j)%7]] >= a[food[(i+j)%7]]) break;
      cnt2++;
      cur[food[(i+j)%7]]++;
    }
    cnt = max(cnt,cnt2);
  }

  cout << ans + cnt << endl;

  return 0;
}