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
//#define int long long
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

P solve(P x, P y){
  //vec a = {x.fs,x.sc,y.fs,y.sc};
  //sort(a.begin(),a.end());
  //return P(a[2],a[3]);
  if(x.sc > y.sc) return P(max(x.fs,y.sc),x.sc);
  else return P(max(x.sc,y.fs),y.sc);
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  
  vector<P> id(1<<21,P(-1,-1));
  vector<int> a(n);
  REP(i,n) cin >> a[i], id[a[i]] = solve(id[a[i]],P(-1,i));
  
  REP(i,21){
    REP(j,1<<21){
      if(j&(1<<i)) id[(1<<i)^j] = solve(id[j],id[(1<<i)^j]);
    }
  }

  int ans = 0;
  REP(i,n-2){
    int res = 0;
    RREP(j,21){
      if((1<<j)&a[i]) continue;
      if(id[res|(1<<j)].fs > i) res |= (1<<j);
    }
    ans = max(ans,res|a[i]);
  }

  cout << ans << endl;

  return 0;
}