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

int n;

bool check(double a){
  double b = n/a;
  return a+b < n;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int t;
  cin >> t;

  REP(_,t){
    cin >> n;
    if(n == 0){
      cout << "Y 0.000000 0.000000" << endl;
      continue;
    }
    double ng = 0, ok = sqrt(n);
    while (abs(ng-ok)>1e-10) {
      double mid = (ng+ok)/2;
      (check(mid)?ok:ng) = mid;
    }
    if(abs(ok+n/ok-n) > 1e-6) cout << "N" << endl;
    else cout << fixed << setprecision(9) << "Y " << ok << " " << (n==0?0:n/ok) << endl;
  }

  return 0;
}