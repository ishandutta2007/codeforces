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
//#define MOD 1000000007
#define MOD 998244353
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
using mint = modint<MOD>;

typedef vector<mint> vec;
typedef vector<vector<mint>> mat;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  int x = 0, y = 0;
  vector<int> b(n);
  REP(i,n){
    cin >> b[i];
    if(a[i]) x += b[i];
    else y += b[i];
  }

  mint invx = (mint)1/x, invy = (mint)1/y;

  //vec invp(3030,1);
  //REP(i,n)

  mint dp[2][3030]; // iposij
  dp[0][0] = 1;
  REP(i,m){
    REP(j,i+2) dp[(i+1)&1][j] = 0;
    REP(j,i+1){
      mint p = (mint)(x+j)/(x+y+j-(i-j)); // pos
      if(i-j > y) continue;
      dp[(i+1)&1][j] += dp[i&1][j]*((mint)1-p);
      dp[(i+1)&1][j+1] += dp[i&1][j]*p;
    }
  }

  vec ans(n,0);
  mint pos = 0, neg = 0;
  REP(i,m+1){
    if(m-i > y) continue;
    pos += dp[m&1][i]*i*invx;
    neg += dp[m&1][i]*(m-i)*invy;
  }
  
  REP(j,n){
    if(a[j]) ans[j] += pos*b[j];
    else ans[j] -= neg*b[j];
  }

  REP(i,n) cout << (ans[i]+b[i]).val() << endl;

  return 0;
}