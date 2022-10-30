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
  int N,Q;
  cin >> N >> Q;

  int M = min(N,15LL);

  vec a(N),s(N+1,0);
  REP(i,N){
    a[i] = i+1;
    s[i+1] = s[i]+a[i];
  }

  int now = 0;
  vec fact(20,1);
  REP(i,19) fact[i+1] = fact[i]*(i+1);

  auto f = [&](){
    vec b(M), used(M,0); int cnt = now;
    REP(i,M){
      int x = cnt / fact[M-1-i];
      cnt -= fact[M-1-i]*x;
      REP(j,M){
        if(used[j]) continue;
        if(x==0){
          b[i] = j; used[j]++;
          break;
        }
        x--;
      }
    }
    REP(i,M) a[N-M+i] = (N-M+1) + b[i];
    FOR(i,N-M,N) s[i+1] = s[i]+a[i];
  };

  REP(_,Q){
    int t; cin >> t;
    if(t==1){
      int l,r; cin >> l >> r;
      cout << s[r] - s[l-1] << endl;
    }
    else{
      int x; cin >> x;
      now += x;
      f();
      //REP(i,N) cout << a[i] << " "; cout << endl;
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