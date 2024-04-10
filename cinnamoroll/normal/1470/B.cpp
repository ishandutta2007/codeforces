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
#define parity(i,j) (1&(i>>j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

vector<int> pri;
void init(int x){
  vector<bool> flag(x+1,false);
  for(int i = 2; i <= x; i++){
    if(flag[i]) continue;
    pri.emplace_back(i);
    for(int j = i; j <= x; j+=i) flag[j] = true;
  }
}
 
map<long long,int> Primefactorization(long long x){
  map<long long, int> mp;
  for(int p:pri){
    int cnt = 0;
    if(p*p > x) break;
    while(x%p==0) x /= p, cnt++;
    if(cnt) mp[p] = cnt;
  }
  if(x != 1) mp[x] = 1;
  return mp;
}

void solve(){
  int N;
  cin >> N;

  vector<int> a(N);
  REP(i,N) cin >> a[i];

  map<vector<int>,int> mp;
  REP(i,N){
    auto tmp = Primefactorization(a[i]);
    vec res;
    ITR(itr,tmp) if(itr->sc%2) res.emplace_back(itr->fs);
    mp[res]++;
  }

  int mx = 0;
  ITR(itr,mp){
    chmax(mx,itr->sc);
  }

  int Q;
  cin >> Q;
  vector<P> q(Q);
  REP(i,Q) cin >> q[i].fs, q[i].sc = i;

  sort(q.begin(),q.end());

  vec ans(Q);

  int now = 0;
  REP(i,Q){
    while(now < q[i].fs && now <= 1){
      map<vector<int>,int> nx;
      int mx2 = 0;
      ITR(itr,mp){
        if(itr->sc % 2) nx[itr->fs] += itr->sc;
        else nx[vec(0)] += itr->sc;
      }
      ITR(itr,nx) chmax(mx2,itr->sc);
      mx = mx2; mp = nx;
      now++;
    }
    ans[q[i].sc] = mx;
  }
  

  REP(i,Q) cout << ans[i] << "\n";

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;
  
  init(1010101);

  while(T--) solve();

  return 0;
}