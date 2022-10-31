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
  int N;
  cin >> N;

  mat C(N,vec(N,0));
  REP(i,N) REP(j,N){
    int c = 1;
    REP(k,N-1-i) c *= (N*2-i-j-2-k), c /= (k+1);
    C[i][j] = c;
  }

  mat a(N,vec(N,0)); int nx = 1;
  RREP(j,N-1){
    int tmp = 0;
    FOR(i,1,N){
      int sum = 0;
      FOR(k,j+1,N) sum += a[i][k];
      a[i][j] = nx - sum - tmp;
      nx += C[i][j+1];
      tmp += a[i][j];
      // debug(nx);
    }
  }

  REP(i,N){
    REP(j,N) cout <<a[i][j] << " ";
    cout << endl;
  }

  mat b = a;
  REP(i,N) RREP(j,N-1) b[i][j] += b[i][j+1];

  int q;
  cin >> q;
  REP(_,q){
    int k; cin >> k;
    int x = 0, y = 0;
    cout << x+1 SP y+1 << endl;
    REP(_,2*N-2){
      if(x+1 < N && k >= b[x+1][y]) x++;
      else y++;
      k -= a[x][y];
      cout << x+1 SP y+1 << endl;
    }
  }

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}