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
#define INF (1LL<<40)
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

int n,k;
vec a;

bool check(int mid){
  int cnt = 0;
  FOR(i,n/2,n){
    cnt += max(0LL,mid-a[i]);
  }
  return cnt <= k;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  a.resize(n);
  REP(i,n) cin >> a[i];

  sort(a.begin(),a.end());
  
  int ok = 0, ng = INF;
  while (abs(ng-ok)>1) {
    int mid = (ng+ok)/2;
    (check(mid)?ok:ng) = mid;
  }

  cout << ok << endl;

  return 0;
}