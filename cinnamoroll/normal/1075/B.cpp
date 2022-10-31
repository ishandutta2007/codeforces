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
#define INF 1LL<<50
#define fst first
#define sec second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef pair<int,int> P;
typedef vector<vector<P>> Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,m;
  cin >> n >> m;

  vector<int> a(n+m);
  REP(i,n+m) cin >> a[i];
  
  vector<int> b(n+m);
  REP(i,n+m) cin >> b[i];
  
  int ans[m] = {};

  vector<int> c;
  REP(i,n+m) if(b[i] == 1) c.pb(a[i]);
  c.pb(INF);

  REP(i,n+m){
    if(b[i] == 1) continue;
    auto itr = lower_bound(c.begin(), c.end(), a[i]);
    abs(*(itr-1)-a[i]) <= abs(*itr-a[i])?ans[distance(c.begin(),itr)-1]++:ans[distance(c.begin(),itr)]++;
  }
  
  
  REP(i,m) cout << ans[i] << " ";
  cout << endl;

  return 0;
}