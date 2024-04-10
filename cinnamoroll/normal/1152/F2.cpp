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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define pb push_back
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

#include <cstdint>

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

  u64 a;

public:
  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 value() const noexcept { return a; }
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

int m;
vec matmul(vec &dp, mat &mt){
  vec ret(m,0);
  REP(i,m) REP(j,m) ret[i] += mt[i][j]*dp[j];
  return ret;
}

mat update(mat &mt){
  mat ret(m,vec(m,0));
  REP(i,m) REP(j,m) REP(k,m) ret[i][j] += mt[i][k]*mt[k][j];
  return ret;
}

void matpow(vec &dp, mat &mt, int k){
  while(k){
    if(k%2) dp = matmul(dp,mt);
    mt = update(mt);
    k /= 2;
  }
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,k,l;
  cin >> n >> k >> l;

  int M = 1<<l;
  m = M*(k+2);

  mat mt(M*(k+2),vec(M*(k+2),0));
  REP(i,k+1){
    REP(j,M){
      int mask = (j<<1)&(M-1);
      mt[i*M+mask][i*M+j] += 1;
      mt[(i+1)*M+(mask|1)][i*M+j] += __builtin_popcount(j)+1;
    }
  }

  vec dp(M*(k+2),0);
  dp[0] = 1;
  matpow(dp,mt,n);

  mint ans = 0;
  REP(i,M) ans += dp[M*k+i];

  cout << ans.value() << endl;

  return 0;
}