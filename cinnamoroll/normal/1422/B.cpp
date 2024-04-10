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
  int N,M;
  cin >> N >> M;

  vector<vector<int>> a(N,vector<int>(M));
  REP(i,N) REP(j,M) cin >> a[i][j];
  
  int ans = 0;
  REP(i,N/2) REP(j,M/2){
    int sum = 0;
    vec b;
    b.push_back(a[i][j]);
    b.push_back(a[N-1-i][j]);
    b.push_back(a[N-1-i][M-1-j]);
    b.push_back(a[i][M-1-j]);
    int res = LINF;
    for(int x:b){
      int tmp = 0;
      for(int y:b) tmp += abs(x-y);
      chmin(res,tmp);
    }
    ans += res;
  }

  if(M%2){
    REP(i,N/2) ans += max(a[i][M/2],a[N-1-i][M/2]) - min(a[i][M/2],a[N-1-i][M/2]);
  }

  if(N%2){
    REP(i,M/2) ans += max(a[N/2][i],a[N/2][M-1-i]) - min(a[N/2][i],a[N/2][M-1-i]);
  }

  cout << ans << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}