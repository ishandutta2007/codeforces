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

  int n,s;
  cin >> n >> s;
  s--;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> b(n);
  REP(i,n) cin >> b[i];
  
  if(a[0] == 0 || (a[s] == 0 && b[s] == 0) ){
    cout << "NO" << endl;
    return 0;
  }

  if(a[s] == 1){
    cout << "Yes" << endl;
    return 0;
  }

  bool f = false;
  FOR(i,s,n) if(a[i] == 1 && b[i] == 1) f = true;

  cout << (f?"YES":"NO") << endl;

  return 0;
}