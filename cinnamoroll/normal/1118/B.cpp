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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define INF (1LL<<60)
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
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  vector<int> sum_e(n+1,0),sum_o(n+1,0);
  REP(i,n){
    sum_o[i+1] = sum_o[i];
    sum_e[i+1] = sum_e[i];
    if(i % 2 == 0) sum_e[i+1] = sum_e[i]+a[i];
    else sum_o[i+1] = sum_o[i]+a[i];
  }

  int ans = 0;
  REP(i,n){
    int odd = 0, eve = 0;
    odd = sum_o[i] + sum_e[n] - sum_e[i+1];
    eve = sum_e[i] + sum_o[n] - sum_o[i+1];
    if(odd == eve) ans++;
  }

  //REP(i,n+1) cout << sum_o[i] SP sum_e[i] << endl;

  cout << ans << endl;

  return 0;
}