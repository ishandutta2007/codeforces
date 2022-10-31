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

int x,c,b,y,k;
bool check(int mid, vec &a){
  int l = b*c/__gcd(b,c);
  l = mid/l;
  int m = mid/b-l;
  int n = mid/c-l;

  int sum = 0;
  REP(i,l+m+n){
    if(i < l) sum += (x+y)*a[i];
    else if(i < l+m) sum += x*a[i];
    else sum += y*a[i];
  }
  return sum >= k;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;

  REP(_,q){
    int n;
    cin >> n;

    vector<int> a(n);
    REP(i,n) cin >> a[i], a[i] /= 100;

    sort(a.rbegin(),a.rend());
    
    cin >> x >> b >> y >> c >> k;

    if(x < y) swap(x,y), swap(b,c);

    int ng = 0, ok = n+1;
    while (abs(ng-ok)>1) {
      int mid = (ng+ok)/2;
      (check(mid,a)?ok:ng) = mid;
    }

    if(ok == n+1) cout << -1 << "\n";
    else cout << ok << "\n";

  }

  return 0;
}