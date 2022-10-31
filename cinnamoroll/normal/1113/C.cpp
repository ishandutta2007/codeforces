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

  int n;
  cin >> n;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int ans = 0;

  vector<int> sum(n+1,0);
  REP(i,n) sum[i+1] = sum[i]^a[i];
  //REP(i,n+1) cout << sum[i] << endl;

  map<int,int> mp_e,mp_o;
  for(int i = 0; i <= n; i+=2){
    mp_e[sum[i]]++;
  }

  for(int i = 1; i <= n; i+=2){
    mp_o[sum[i]]++;
  }

  ITR(itr,mp_o){
    ans += itr->sc*(itr->sc-1);
  }

  ITR(itr,mp_e){
    ans += itr->sc*(itr->sc-1);
  }

  cout << ans/2 << endl;

  return 0;
}