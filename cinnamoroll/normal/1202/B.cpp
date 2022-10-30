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

  mat ans(10,vec(10));
  vec tmp;
  REP(i,10){
    REP(j,10){
      if(i>j) continue;
      tmp.assign(11,INF);
      REP(k,10){
        REP(x,11){
          int cur = i*x;
          REP(y,11){
            if(x==0 && y == 0) continue;
            if((cur+j*y)%10 == k){
              tmp[k] = min(tmp[k],x+y);
              break;
            }
          }
        }
      }

      int res = 0;
      REP(k,s.size()-1){
        int cur = (s[k+1]-s[k]+10)%10;
        if(tmp[cur] == INF){
          res = -1; break;
        }
        res += tmp[cur];
      }
      ans[i][j] = ans[j][i] = (res==-1?-1:res-s.size()+1);
    }
  }

  REP(i,10){
    REP(j,10) cout << ans[i][j] << " ";
    cout << endl;
  }

  return 0;
}