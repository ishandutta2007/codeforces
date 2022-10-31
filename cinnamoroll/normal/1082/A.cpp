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
#define INF 1LL<<60
#define fs first
#define sc second
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

  int t;
  cin >> t;

  REP(_,t){
    int n,d,x,y;
    cin >> n >> x >> y >> d;

    if(abs(x-y)%d == 0){
      cout << abs(x-y)/d << endl;
      continue;
    }

    if((n-y)%d != 0 && (y-1)%d != 0){
      cout << -1 << endl;
      continue;
    }

    int tmp1 = (x-1)/d + ((x-1)%d==0?0:1) + (y-1)/d, tmp2 = (n-x)/d + ((n-x)%d==0?0:1) + (n-y)/d;

    if((n-y)%d != 0){
      cout << (x-1)/d + ((x-1)%d==0?0:1) + (y-1)/d << endl;
      continue;
    }

    if((y-1)%d != 0){
      cout << (n-x)/d + ((n-x)%d==0?0:1) + (n-y)/d << endl;
      continue;
    }

    cout << min(tmp1,tmp2) << endl;

  }

  return 0;
}