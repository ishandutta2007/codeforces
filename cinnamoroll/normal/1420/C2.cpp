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

  vector<int> a(N+2);
  REP(i,N) cin >> a[i+1];
  
  a[0] = 0; a[N+1] = -LINF;
  int ans = 0;
  REP(i,N) ans += max(0LL,a[i+1]-a[i]);

  cout << ans << "\n";

  auto calc = [&](int l, int r, int pm){
    if(l==r) return;
    if(l+1<r){
      ans += max(0LL,a[l]-a[l-1])*pm;
      ans += max(0LL,a[l+1]-a[l])*pm;
      ans += max(0LL,a[r]-a[r-1])*pm;
      ans += max(0LL,a[r+1]-a[r])*pm;
    }
    else{
      ans += max(0LL,a[l]-a[l-1])*pm;
      ans += max(0LL,a[l+1]-a[l])*pm;    
      ans += max(0LL,a[r+1]-a[r])*pm;  
    }
  };

  REP(_,Q){
    int l,r;
    cin >> l >> r;
    calc(l,r,-1);
    swap(a[l],a[r]);
    calc(l,r,1);
    cout << ans << "\n";
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}