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

  int n,m,k;
  cin >> n >> m >> k;

  vector<int> a(n,0);
  REP(i,m){
    int x;
    cin >> x;
    a[x]++;
  }
  
  vector<int> b(k);
  REP(i,k) cin >> b[i];
  
  int now = -1;
  vec c(n);
  REP(i,n){
    if(!a[i]) now = i;
    c[i] = now;
  }

  int ans = INF;
  REP(i,k){
    if(c[0]==-1) break;
    int cur = 0, sum = 0;
    while(1){
      sum++;
      if(cur+(i+1) >= n){
        ans = min(ans,b[i]*sum);
        break;
      }
      if(cur == c[cur+(i+1)]) break;
      cur = c[cur+(i+1)];
    }
  }

  if(ans != INF)cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}