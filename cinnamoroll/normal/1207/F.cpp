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
#define ll long long
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
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
 
int main(){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
 
  int q;
  scanf("%d",&q);
 
  int n = 711;
  mat a(n,vec(n,0));
 
  vec b(5e5+10,0);
 
  while(q--){
    int t,x,y;
    scanf("%d %d %d",&t,&x,&y);
    if(t == 1){
      for(int i = 1; i < n; i++){
        a[i][x%i] += y;
      }
      b[x] += y;
    }
    else{
      if(x < n) printf("%lld\n",a[x][y]);
      else{
        ll res = 0;
        int id = y;
        while(id <= (int)5e5) res += b[id], id += x;
        printf("%lld\n",res);
      }
    }
  }
 
  return 0;
}