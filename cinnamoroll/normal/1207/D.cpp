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
//#define MOD 1000000007
#define MOD 998244353
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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vec fact(n+1,1);
  FOR(i,1,n+1)fact[i] = fact[i-1]*i;

  mint ans = fact[n];

  vector<P> a(n);
  map<int,int> mp1,mp2;
  REP(i,n){
    cin >> a[i].fs >> a[i].sc;
    mp1[a[i].fs]++; mp2[a[i].sc]++;
  }

  sort(a.begin(),a.end());

  mint tmp = 1;

  ITR(itr,mp1) tmp *= fact[itr->sc]; ans -= tmp; tmp = 1;
  ITR(itr,mp2) tmp *= fact[itr->sc]; ans -= tmp; tmp = 1;

//  debug(ans.val());

  bool flag = true;
  REP(i,n-1) if(a[i].sc > a[i+1].sc) flag = false;
  if(!flag){
    cout << ans.val() << endl;
    return 0;
  }

  int now = a[0].fs;
  map<int,int> mp;
  REP(i,n){
    if(now == a[i].fs) mp[a[i].sc]++;
    else{
      ITR(itr,mp) tmp *= fact[itr->sc];
      mp.clear();
      now = a[i].fs;
      mp[a[i].sc]++;
    }
  }

  ITR(itr,mp) tmp *= fact[itr->sc];

  cout << (tmp+ans).val() << endl;

  return 0;
}