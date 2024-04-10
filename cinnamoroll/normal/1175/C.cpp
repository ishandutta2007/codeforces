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

const int N = 2e5+10;
vector<int> a;
int n,k;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  REP(_,t){
    cin >> n >> k;
    a.assign(n,0);
    REP(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    
    int mn = INF, ans;
    REP(i,n){
      if(i+k >= n) break;
      if(mn > a[i+k]-a[i]){
        mn = min(mn,a[i+k]-a[i]);
        ans = (a[i+k]+a[i])/2;
      }
    }

    cout << ans << endl;

  }

  return 0;
}