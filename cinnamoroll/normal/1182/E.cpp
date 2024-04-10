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
//#define MOD 998244353
const double EPS = 1e-9;
#define INF (1LL<<60)
#define D double
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);i--)
#define REP(i,n)  FOR(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;


const int MODI = 1000000006;
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
    return modint(*this).value() == rhs.value();
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
using mint = modint<MODI>;

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
  m = dp.size();
  while(k){
    if(k%2) dp = matmul(dp,mt);
    mt = update(mt);
    k /= 2;
  }
}



void add(int &a, int b){
  a = ((a+b) % MOD + MOD) % MOD;
}

inline int mul(int a, int b) {
    add(a,0); add(b,0);
    #if !defined(_WIN32) || defined(_WIN64)
      return (int) ((long long) a * b % MOD);
    #endif
      unsigned long long x = (long long) a * b;
      unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (MOD)
      );
      return m;
}

inline int modpow(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
      }
      a = mul(a, a);
      b >>= 1;
  }
  return res;
}

inline int inv(int a) {
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    return u;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,x,y,z,c;
  cin >> n >> x >> y >> z >> c;

  vec dp = {0,0,1,0,1,0,1,0,0};
  mat mt(9,vec(9,0));
  REP(i,3) REP(j,3) mt[i][j*3+i] = 1;
  REP(i,6) mt[i+3][i] = 1;

  matpow(dp,mt,n-3);

  int ans = 1;

  ans = mul(ans,modpow(x,dp[0].val()));
  ans = mul(ans,modpow(y,dp[1].val()));
  ans = mul(ans,modpow(z,dp[2].val()));
  vec dp2 = {0,0,0,1,1};
  mat mt2(5,vec(5,0));
  mt2[0][1] = mt2[0][0] = mt2[0][2] = mt2[1][0] = mt2[2][1]
   = mt2[3][4] = mt2[3][3] = mt2[4][4] = 1;
  mt2[0][3] = 2;

  matpow(dp2,mt2,n-3);

  ans = mul(ans,modpow(c,(dp2[0]).val()));

  cout << ans << endl;

  return 0;
}