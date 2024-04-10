
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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;
 
void ng(){
  cout << "No" << endl;
  exit(0);
}
 
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int k;
  cin >> k;
 
  mat a(k);
  map<int,int> mp;
  vec sum(k,0);
  int tot = 0;
  REP(i,k){
    int n;
    cin >> n;
    a[i].resize(n);
    REP(j,n) cin >> a[i][j], sum[i] += a[i][j], mp[a[i][j]] = i;
    sort(a[i].begin(),a[i].end());
    tot += sum[i];
  }
  
  if(tot%k) ng();
 
  tot /= k;
  vector<vector<P>> bit(1<<k,vector<P>(k,P(INF,INF)));
  bool check[1<<16] = {};
 
  REP(i,k){
    REP(j,a[i].size()){
      vector<P> cur(k,P(INF,INF));
      int store = a[i][j], want = tot-(sum[i]-store), mask = (1<<i), id = i;
      bool flag = true;
      while(1){
        if(store == want) {cur[i] = P(want,id); break;}
        if(mp.count(want)==0 || (1<<mp[want])&mask) {flag = false; break;}
        cur[mp[want]] = P(want,id);
        id = mp[want];
        mask |= (1<<id);
        want = tot-(sum[id]-want);
      }
      if(flag) bit[mask] = cur, check[mask] = true;
    }
  }
 
  // REP(i,1<<k){
  //   cout << bit[i][0].fs << endl;
  // }
 
  vec dp(1<<k,-1); dp[0] = 0;
  REP(i,1<<k){
    if(dp[i] == -1) continue;
    int mask = ((1<<k)-1)^i;
    for(int j = mask;j>0;j--){
      j &= mask;
      if(!check[j]) continue;
      dp[i|j] = i;
      
    }
  }
 
  if(dp[(1<<k)-1] == -1) ng();
  cout << "Yes" << endl;
  vector<P> ans(k,P(INF,INF));
  int in = (1<<k)-1;
  while(in){
    int mask = in^dp[in];
    REP(i,k) ans[i] = min(ans[i],bit[mask][i]);
    in = dp[in];
  }
 
  REP(i,k) cout << ans[i].fs SP ans[i].sc+1 << endl;
 
  return 0;
}