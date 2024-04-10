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
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

void solve(){
  string S;
  int x;
  cin >> S >> x;
  int N = S.size();

  if(x==1){
    int ans = 0;
    REP(i,N) ans += S[i]=='1';
    cout << ans << endl;
    return;
  }

  vec list, f(1<<(x+1),1);
  REP(i,1<<(x+1)){
    if(!parity(i,0)) f[i] = 0;
    REP(j,x) if(parity(i,j)&&parity(i,j+1)) f[i] = 0;
    if(!f[i]) continue;
    if(parity(i,x)){
      f[i] = 0;
      REP(j,x+1) REP(k,j) if(parity(i,j)&&parity(i,k)&&x%(j-k)==0&&(j-k)!=x) f[i] = 1;
    }
    if(f[i]) list.push_back(i);
  }
  
  vec dp(1<<(x+1)), nx(1<<(x+1));
  auto calc = [&](vec &a){
    int N = a.size();
    // REP(i,N) cout << a[i] << " "; cout << endl;
    for(int v:list) dp[v] = INF;
    dp[1] = 0;
    REP(i,N){
      for(int v:list) nx[v] = dp[v]+1;
      for(int v:list){
        int b = ((v<<a[i])|1) & ((1<<(x+1))-1);
        if(f[b]) chmin(nx[b],dp[v]);
      }
      for(int v:list) dp[v] = nx[v];
    }
    int res = INF;
    for(int v:list) chmin(res,dp[v]);
    return res;
  };

  int ans = 0; vec tmp;
  REP(i,N){
    if(S[i]=='1') ans += calc(tmp), tmp.clear();
    else tmp.push_back(S[i]-'0');
  }
  ans += calc(tmp);

  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}