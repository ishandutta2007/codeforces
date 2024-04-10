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
#define INF (int)1e5
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

  REP(_,q){
    int n;
    cin >> n;

    int Y = -INF, YY = INF, X = -INF, XX = INF;
    bool flag = true;
    REP(_,n){
      int x,y;
      int a[4];
      cin >> x >> y;
      REP(i,4) cin >> a[i];

      if(!a[0]) X = max(X,x);
      if(!a[1]) YY = min(y,YY);
      if(!a[2]) XX = min(x,XX);
      if(!a[3]) Y = max(y,Y);

      if(range(x,X,XX+1) || (x<X&&a[2]) || (x>XX&&a[0])) ;
      else flag = false;

      if(range(y,Y,YY+1) || (y<Y&&a[1]) || (y>YY&&a[3])) ;
      else flag = false;      
    }
    if(flag) cout << 1 SP X SP Y << "\n";
    else cout << 0 << "\n";
  }

  return 0;
}