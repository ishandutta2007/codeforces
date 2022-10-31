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

  vector<P> a(n);
  REP(i,n) cin >> a[i].fs, a[i].fs--, a[i].sc = i;
  
  sort(a.rbegin(),a.rend());

  vector<P> ans;
  REP(i,n-1) ans.push_back(P(a[i].sc*2,a[i+1].sc*2));

  vec dist(n);
  REP(i,n) dist[i] = a[i].sc*2;

  REP(i,n){
    ans.push_back(P(a[i].sc*2+1,dist[a[i].fs+i]));
    if(a[i].fs+i == dist.size()-1) dist.push_back(a[i].sc*2+1);
  }

  for(P p:ans) cout << p.fs+1 SP p.sc+1 << "\n";

  return 0;
}