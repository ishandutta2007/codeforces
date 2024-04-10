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
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(int itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(int itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef long long ll;
typedef pair<ll,ll> P;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;
  
  int a[n];
  REP(i,n) cin >> a[i];
  
  int cnt = 0,page = 0;
  REP(i,n){
      int ans = page;
      cnt += a[i];
      page = cnt/m;
      cout << page - ans << " ";
  }

  return 0;
}