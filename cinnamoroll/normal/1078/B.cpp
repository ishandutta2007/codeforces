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
//#define int long long
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

  vector<int> a(101,0);
  int cnt = 0;
  REP(i,N){
    int x;
    cin >> x;
    a[x]++;
  }

  FOR2(i,1,100) if(a[i]) cnt++;
  if(cnt==2){
    cout << N << endl;
    return;
  }

  vector<P> b(100);
  REP(i,100) b[i] = P(a[i+1],i+1);

  sort(b.rbegin(),b.rend());

  auto check = [&](int x, int K){
    //cout << x SP K << endl;
    mat dp(K+1,vec(x*K+1,0));
    dp[0][0] = 1;
    FOR2(j,1,100){
      int loop = a[j];
      if(j==x) loop = K-1;
      REP(_,loop){
        RREP(num,K) RREP(k,x*K) if(k+j <= x*K && dp[num][k]) dp[num+1][k+j] = 1; 
      }
    }
    return dp[K][x*K] == 0;
  }; 
  
  int ans = 0;
  REP(i,100){
    if(ans >= b[i].fs) break;
    int ng = b[i].fs+1, ok = ans;
    while (abs(ng-ok)>1) {
      int mid = ng+(ok-ng)/2;
      (check(b[i].sc,mid)?ok:ng) = mid;
    }
    chmax(ans,ok);
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