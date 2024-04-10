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

  int n,q;
  cin >> n >> q;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int N = 2e5+10;
  vec L(N,-1), R(N,-1), cnt(N,0);

  REP(i,n){
    if(L[a[i]] == -1) L[a[i]] = i;
    R[a[i]] = i+1;
    cnt[a[i]]++;
  }

  int r = 0, mx = 0, ans = 0;
  for(int l = 0;l < n;){
    r = R[a[l]];
    mx = 0; int sum = 0;
    for(;l<r;l++){
      r = max(r,R[a[l]]);
      mx = max(mx,cnt[a[l]]);
      sum++;
    }
    //cout << l SP sum SP mx << endl;
    ans += sum-mx;
  }

  cout << ans << endl;

  return 0;
}