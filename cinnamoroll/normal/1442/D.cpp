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
  int N,K;
  cin >> N >> K;

  vector<int> x(N);
  mat a(N);
  REP(i,N){
    cin >> x[i];
    a[i].resize(x[i]);
    REP(j,x[i]) cin >> a[i][j];
  }

  sort(x.begin(),x.end());
  sort(a.begin(),a.end(),[](vec x, vec y){return x.size() < y.size();});

  vec c(N),v(N,0);
  REP(i,N){
    c[i] = min(x[i],K);
    REP(j,c[i]) v[i] += a[i][j];
  }

  vec list[N];
  function<void(vec, int, int)> dfs = [&](vec dp, int l, int r){
    if(l+1==r){
      list[l] = dp;
      return;
    }
    int mid = (l+r)/2;
    vec memo = dp;
    FOR(i,l,mid){
      RREP2(j,K-c[i]) chmax(dp[j+c[i]],dp[j]+v[i]);
    }
    dfs(dp,mid,r);
    dp = memo;
    FOR(i,mid,r){
      RREP2(j,K-c[i]) chmax(dp[j+c[i]],dp[j]+v[i]);
    }    
    dfs(dp,l,mid);
  };
  vec tmp = vec(K+1,-LINF); tmp[0] = 0;
  dfs(tmp,0,N);

  int ans = 0;
  REP(i,N){
    chmax(ans,list[i][K]);
    int sum = 0;
    REP(j,min(K,x[i])){
      sum += a[i][j];
      chmax(ans,list[i][K-1-j]+sum);
    }
  }
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