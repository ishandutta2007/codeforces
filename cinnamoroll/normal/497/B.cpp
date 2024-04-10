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

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vec b(n+2,0), c(n+2,0);
  REP(i,n){
    b[i+1] = b[i] + (a[i]==1);
    c[i+1] = c[i] + (a[i]==2);
  }

  if(a.back()==2) swap(b,c);

  b[n+1] = c[n+1] = INF;

  //REP(i,n+2) cout << b[i] SP c[i] << endl;

  vector<P> ans;
  FOR(i,1,n+1){
    int id = 0, win = 0 , lose = 0;
    bool last;
    while(id < n){
      int lb = lower_bound(b.begin()+id,b.end(),b[id]+i) - b.begin();
      int lc = lower_bound(c.begin()+id,c.end(),c[id]+i) - c.begin();
      //cout << lb SP lc << endl;
      id = min(lb,lc);
      if(lb < lc) win++, last = true;
      else lose++, last = false;
    }
    if(id == n && win > lose && last) ans.emplace_back(P(win,i));
  }

  sort(ans.begin(),ans.end());

  cout << ans.size() << endl;
  REP(i,ans.size()) cout << ans[i].fs SP ans[i].sc << endl;

  return 0;
}