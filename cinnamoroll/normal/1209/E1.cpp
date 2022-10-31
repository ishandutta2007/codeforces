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

  int t;
  cin >> t;

  REP(_,t){
    int n,m;
    cin >> n >> m;

    vector<P> mx(100,P(0,0));
    REP(i,100) mx[i].sc = i; 
    vector<vector<int>> a(n,vector<int>(100,0));
    REP(i,n) REP(j,m) cin >> a[i][j], mx[j].fs = max(mx[j].fs,a[i][j]);
    
    sort(mx.rbegin(),mx.rend());
    int ans = 0;
    REP(i,n){
      REP(j,n){
        REP(k,n){
          int res = 0;
          REP(l,n) res += max({a[l][mx[0].sc],a[(l+i)%n][mx[1].sc],a[(l+j)%n][mx[2].sc],a[(l+k)%n][mx[3].sc]});
          ans = max(ans,res);
        }
      }
    }
    cout << ans << endl;
  }

  return 0;
}