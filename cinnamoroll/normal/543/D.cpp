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

#include <cstdint>

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

  u64 a;

public:
  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 val() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr bool operator==(const modint rhs) const noexcept {
    return modint(*this).val() == rhs.val();
  }
  modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
using mint = modint<MOD>;
typedef vector<mint> vec;
typedef vector<vector<mint>> mat;

const int N = 2e5+10;
vector<int> edge[N];
vec dp(N,1),ans(N);

void dfs(int no, int par){
  for(int to: edge[no]){
    if(to==par) continue;
    dfs(to,no);
    dp[no] *= (dp[to]+1)+1; 
  }
  dp[no] -= 1;
}

void dfs2(int no, int par){
  ans[no] = dp[no]+1;
  vec tmp;
  for(int to:edge[no]) tmp.push_back(dp[to]+2);
  int x = tmp.size();
  vec L(x+1,1),R(x+2,1);
  REP(i,x) L[i+1] = L[i]*tmp[i];
  RREP(i,x) R[i+1] = R[i+2]*tmp[i]; 
  int id = 0;
  for(int to:edge[no]){
    if(to==par) {id++;continue;}
    mint now1 = dp[no], now2 = dp[to];
    dp[no] = L[id]*R[id+2];
    //debug(dp[no].val());
    dp[no] -= 1;
    dp[to] += 1;
    dp[to] *= dp[no]+2;
    dp[to] -= 1;
    dfs2(to,no);
    dp[no] = now1;
    dp[to] = now2;
    id++;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  REP(i,n-1){
    int x; cin >> x;
    edge[i+1].push_back(x-1);
    edge[x-1].push_back(i+1);
  }

  dfs(0,-1);

  dfs2(0,-1);

  REP(i,n) cout << ans[i].val() << " ";

  return 0;
}