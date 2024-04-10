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
//                            
//                        
//                
//   
//    
//      
//
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

template<class Z> Z rng(Z a, Z b) {
  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<Z>(a, b - 1)(mt);
}
 
struct RollingHash {
  static constexpr uint64_t P0 = 4e9 + 7;
  static constexpr uint64_t P1 = 4e9 + 9;
  static uint64_t B0;
  static uint64_t B1;
  static vector<uint64_t> powB0;
  static vector<uint64_t> powB1;
  int n;
  vector<uint64_t> h0;
  vector<uint64_t> h1;
  void init(string s){
    n = s.size();
    h0.resize(n+1); h1.resize(n+1);
    for (int i = 0; i < n; ++i) {
      h0[i + 1] = (h0[i] * B0 + s[i]) % P0;
      h1[i + 1] = (h1[i] * B1 + s[i]) % P1;
    }
    while (powB0.size() <= n) {
      powB0.push_back(powB0.back() * B0 % P0);
      powB1.push_back(powB1.back() * B1 % P1);
    }
  }
  void add(char in) {
      h0.push_back((h0.back() * B0 + in) % P0);
      h1.push_back((h1.back() * B1 + in) % P1);
      powB0.push_back(powB0.back() * B0 % P0);
      powB1.push_back(powB1.back() * B1 % P1);
  }
  uint64_t get0(int l, int r) { return (h0[r] + (P0 - h0[l]) * powB0[r - l]) % P0; }
  uint64_t get1(int l, int r) { return (h1[r] + (P1 - h1[l]) * powB1[r - l]) % P1; }
  pair<uint64_t, uint64_t> get(int l, int r) {
      pair<uint64_t, uint64_t> a;
      a.first = get0(l, r);
      a.second = get1(l, r);
      return a;
  }
  bool match(int l0, int r0, int l1, int r1) {
    return get0(l0, r0) == get0(l1, r1) and get1(l0, r0) == get1(l1, r1);
  }
};
uint64_t RollingHash::B0 = rng<unsigned>(1, RollingHash::P0);
uint64_t RollingHash::B1 = rng<unsigned>(1, RollingHash::P1);
vector<uint64_t> RollingHash::powB0{1};
vector<uint64_t> RollingHash::powB1{1};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  string s;
  cin >> n >> m >> s;

  RollingHash rhs[26];
  REP(i,26){
    string t = s;
    REP(j,t.size()) t[j] = (t[j]=='a'+i);
    rhs[i].init(t);
  }

  REP(_,m){
    int x,y,len;
    cin >> x >> y >> len;
    x--; y--;
    vector<P> a[2];
    REP(i,26){
      a[0].emplace_back(rhs[i].get(x,x+len));
      a[1].emplace_back(rhs[i].get(y,y+len));
    }
    sort(a[0].begin(),a[0].end());
    sort(a[1].begin(),a[1].end());
    if(a[0]==a[1]) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }

  return 0;
}