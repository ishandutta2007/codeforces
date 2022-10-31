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

vec a(15000001,0);

void solve(){
  int N;
  cin >> N;

  init(15000001);

  int g = 0;
  
  vec b(N);
  REP(i,N){
    cin >> b[i];
    g = __gcd(g,b[i]);
  }

  REP(i,N) a[b[i]/g]++;

  int mx = 0;
  for(int p:pri){
    int tmp = 0;
    for(int i = p; i < a.size(); i+=p) tmp += a[i];
    chmax(mx,tmp);
  }

  if(mx==0) cout << -1 << endl;
  else cout << N-mx << endl;

}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;

  while(T--) solve();

  return 0;
}