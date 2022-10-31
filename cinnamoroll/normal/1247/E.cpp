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
#define MOD 1000000007
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
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
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
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

mint dp[2][2012][2012] = {};
int sum1[2012][2012] = {}, sum2[2012][2012] = {};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<string> s(n);
  REP(i,n) cin >> s[i];

  if(n==1 && m==1){
    cout << 1 << endl;
    return 0;
  }

  REP(i,n) REP(j,m) sum1[i][j] = sum2[i][j] = (s[i][j]=='R');

  REP(i,n) REP(j,m-1) sum1[i][j+1] += sum1[i][j];
  REP(j,m) REP(i,n-1) sum2[i+1][j] += sum2[i][j];

  dp[0][0][0] = dp[1][0][0] = 1;
  dp[0][0][1] = dp[1][1][0] = MOD-1;
  REP(i,n) REP(j,m){
    //tate move
    if(j) dp[0][i][j] += dp[0][i][j-1];
    int id = n-(sum2[n-1][j]-sum2[i][j]);
    dp[1][i+1][j] += dp[0][i][j];
    dp[1][id][j] -= dp[0][i][j];
    //yoko move
    if(i) dp[1][i][j] += dp[1][i-1][j];
    id = m-(sum1[i][m-1]-sum1[i][j]);
    dp[0][i][j+1] += dp[1][i][j];
    dp[0][i][id] -= dp[1][i][j];
  }

  mint ans = dp[0][n-1][m-1] + dp[1][n-1][m-1];
  cout << ans.val() << endl;

  return 0;
}