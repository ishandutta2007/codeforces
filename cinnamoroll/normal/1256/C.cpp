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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int n,m,d;
  cin >> n >> m >> d;
 
  vector<int> a(m);
  REP(i,m) cin >> a[i];
  
  int now = 0;
  REP(i,m){
    now += d+a[i]-1;
  }
 
  if(now+d <= n){
    cout << "NO" << endl;
    return 0;
  }
 
  cout << "YES" << endl;
  int sum = accumulate(a.begin(),a.end(),0LL);
  vec ans(n,0);
  int nokori = n-sum, sukima = d-1, id = 0;
  REP(i,n){
    if(nokori){
      if(sukima) sukima--, nokori--;
      else{
        REP(j,a[id]) ans[i+j] = id+1;
        i += a[id]-1; id++; sukima = d-1;
      }
    }
    else{
        REP(j,a[id]) ans[i+j] = id+1;
        i += a[id]-1; id++;      
    }
  }
 
  REP(i,n) cout << ans[i] << " ";
  cout << endl;
 
  return 0;
}