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

typedef vector<int> vec;
typedef vector<vector<int>> mat;

mint dp[2][20][2] = {};

void reset(int i){
  REP(j,20) REP(k,2) dp[i][j][k] = 0;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int cnt = 1, k = 0;
  while(cnt*2 <= n) k++, cnt *= 2;

  dp[0][k][0] = 1;
  if(cnt/2*3 <= n) dp[0][k-1][1] = 1;

  mat a(22,vec(2,0));
  FOR(i,1,n+1){
    int tmp = i, cnt = 0;
    bool f = (tmp%3==0);
    while(1){
      a[cnt][0]++;
      if(f) a[cnt][1]++;
      if(tmp%2) break;
      tmp /= 2;
      cnt++;
    }
  }

  REP(i,n){
    reset((i+1)&1);
    REP(x,20) REP(y,2){
      dp[(i+1)&1][x][y] += dp[i&1][x][y]*max(0LL,a[x][y]-1-i);
      if(x != 0) dp[(i+1)&1][x-1][y] += dp[i&1][x][y]*(a[x-1][y]-a[x][y]);
      if(y) dp[(i+1)&1][x][0] += dp[i&1][x][1]*(a[x][0]-a[x][1]);
    }
  }

  cout << dp[(n-1)&1][0][0].val() << endl;

  return 0;
}