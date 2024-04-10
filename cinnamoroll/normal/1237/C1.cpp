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

  int n;
  cin >> n;

  using T = tuple<int,int,int,int>;

  vector<int> x(n),y(n),z(n);
  REP(i,n) cin >> x[i] >> y[i] >> z[i];
  
  vec flag(n,0);
  vector<P> ans;

  REP(i,n){
    if(flag[i]) continue;
    flag[i]++;
    bool check = true;
    int X = INF, Y , Z, id;
    REP(j,n){
      if(flag[j]) continue;
      if(X == INF){
        X = x[j], Y = y[j], Z = z[j];
        id = j; continue;
      }
      if(range(x[j],min(x[i],X),max(x[i],X)+1) && range(y[j],min(y[i],Y),max(y[i],Y)+1) && range(z[j],min(z[i],Z),max(z[i],Z)+1)){
        X = x[j], Y = y[j], Z = z[j];
        id = j; continue;        
      }
    }
    flag[id]++;
    ans.push_back(P(i+1,id+1));
  }

  REP(i,n/2) cout << ans[i].fs SP ans[i].sc << endl;

  return 0;
}