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

  int n,l,w;
  cin >> n >> l >> w;

  vec L,R;
  int ans = 0, cntL = 0, cntR = 0;
  REP(_,n){
    int x,y;
    cin >> x >> y;
    if(y==1){
      L.push_back(x);
      if(x<0) cntL++;
    }
    else{
      R.push_back(x);
      if(x+l>0) cntR++;
    }
  }

  ans += cntL*cntR;
  sort(L.begin(),L.end());
  sort(R.begin(),R.end());

  if(w==1){
    cout << ans << endl;
    return 0;
  }

  REP(i,L.size()){
    if(L[i]<0) continue;
    ans += R.end() - upper_bound(R.begin(),R.end(),(2*L[i])/(w-1)+L[i]-l);
  }

  REP(i,R.size()){
    if(R[i]+l>0) continue;
    ans += lower_bound(L.begin(),L.end(),R[i]+l+(2*(R[i]+l))/(w-1)) - L.begin();
  }

  cout << ans << endl;

  return 0;
}