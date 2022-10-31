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

  int n,q;
  cin >> n >> q;

  vector<int> a(n);
  REP(i,n) cin >> a[i];

  mat dp(n,vec(20,INF));
  vec nx(20,INF);
  RREP(i,n){
    REP(j,20){
      if(a[i] & (1<<j)){
        if(nx[j] != INF){
          dp[i][j] = min(dp[i][j],nx[j]);
          REP(k,20) dp[i][k] = min(dp[i][k],dp[nx[j]][k]);
        }
        nx[j] = i;
      }
    }
  }
  
  REP(_,q){
    int x,y;
    cin >> x >> y; x--; y--;
    bool flag = false;
    REP(i,20) if((a[y]&(1<<i)) && dp[x][i] <= y) flag = true;
    if(flag) cout << "Shi" << endl;
    else cout << "Fou" << endl;
  }

  return 0;
}