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

  int q;
  cin >> q;

  int m = 1, cnt = 1;
  vec a = {1};
  while(cnt <= 1e18) m++, cnt*=3, a.push_back(cnt);
  reverse(a.begin(),a.end());

  REP(_,q){
    int n;
    cin >> n;

    vec b(m,0);
    REP(i,m){
      while(n>=a[i]) n-=a[i], b[i]++;
    }

    bool flag = true;
    while(flag){
      flag = false;
      REP(i,m){
        if(b[i]==2){
          flag = true;
          b[i-1]++;
          FOR(j,i,m) b[j] = 0;
          break;
        }
      }
    }

    int ans = 0;
    REP(i,m) ans += b[i]*a[i];

    cout << ans << "\n";
  }

  return 0;
}