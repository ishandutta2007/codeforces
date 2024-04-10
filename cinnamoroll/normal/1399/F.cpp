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

vec memo;
vector<P> a;

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}

template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}

void dfs(int no){
  if(memo[no]) return;
  vec dp(6060,0); int id = 0;int mx = 0;
  FOR(i,no+1,a.size()){
    if(a[no].sc < a[i].sc) continue;
    dfs(i);
    while(id < a[i].fs) chmax(mx,dp[id++]);
    chmax(dp[a[i].sc],mx + memo[i]);
  }
  REP(i,6060) chmax(memo[no],dp[i]);
  memo[no]++;
}

void init(int N){
  memo.assign(N+1,0);
  a.resize(N);
}

void solve(){
  int N;
  cin >> N;

  init(N);

  vec b = {-INF,INF};
  REP(i,N) cin >> a[i].fs >> a[i].sc, b.push_back(a[i].fs), b.push_back(a[i].sc);
  a.push_back(P(-INF,INF));

  auto r = compress(b);
  auto v = dict(r);

  REP(i,N+1) a[i].fs = v[a[i].fs], a[i].sc = v[a[i].sc];
  REP(i,N) assert(a[i]!=a[i+1]);

  auto f = [](P a, P b){
    if(a.fs != b.fs) return a.fs < b.fs;
    else return a.sc > b.sc;
  };
  sort(a.begin(),a.end(),f);

  //REP(i,N+1) cout << a[i].fs SP a[i].sc << endl;

  dfs(0);
  //REP(i,N+1) cout << memo[i] << endl;

  cout << memo[0]-1 << endl;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while(T--) solve();

  return 0;
}