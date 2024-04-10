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
#define MOD 998244353
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

const int NMAX = 2e5;
vector<int> p(NMAX), edge[NMAX], used(NMAX,0);
mat dp(NMAX,vec(3,0));

void dfs(int no){
  used[no]++;
  if(edge[no].size() == 0) dp[no][2] = 1;
  else{
    dp[no][0] = 1;
    for(auto to:edge[no]){
      dfs(to);
      vec tmp(3,0);
      tmp[0] += dp[no][0]*(dp[to][0]+dp[to][2]);
      tmp[1] += dp[no][0]*(dp[to][1]+dp[to][2]) + dp[no][1]*(dp[to][0]+dp[to][2]);
      tmp[2] += (dp[no][2]+dp[no][1])*(dp[to][1]+dp[to][2]) + dp[no][2]*(dp[to][0]+dp[to][2]);
      dp[no] = tmp;
    }
  }
}
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  REP(i,n-1) cin >> p[i], edge[p[i]-1].push_back(i+1);

  dfs(0);

  cout << (dp[0][0]+dp[0][2]).value() << endl;

  return 0;
}