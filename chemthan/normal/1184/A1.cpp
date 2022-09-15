#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define debug(a) cerr << #a << ": " << (a) << '\n';
#define debug_arr(a, n) { cerr << #a << " "; rep(i, 0, n) cerr << a[i] << " \n"[i == n]; }
#define debug_two(a, b) cerr << #a << ": " << (a) << ", " << #b << ": " << (b) << '\n';
mt19937 rng(static_cast<unsigned int>(chrono::steady_clock::now().time_since_epoch().count()));

template <typename num_t>
inline void add_mod(num_t& a, const int& b, const int& m) { a = (a + b) % m; if (a >= m) a -= m; if (a < 0) a += m; }
template <typename num_t>
inline bool update_max(num_t& a, const num_t& b) { return a < b ? a = b, true : false; }
template <typename num_t>
inline bool update_min(num_t& a, const num_t& b) { return a > b ? a = b, true : false; }
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) { return !lhs ? rhs : gcd(rhs % lhs, lhs); }
template <typename num_t>
num_t pw(num_t n, num_t k, const num_t& mod) {
  if (k == -1) k = mod - 2;
  num_t res = 1; for (; k > 0; k >>= 1) { if (k & 1) res = 1ll * res * n % mod; n = 1ll * n * n % mod; }
  return res % mod;
}

typedef long long ll;
const int inf = 1e9 + 7;
const int mod = 998244353;
const ll ll_inf = 9ll * inf * inf + 7;
const int MAX_N = 1000 + 7;

void solve() {
  long long r;
  cin >> r;
  for (long long x = 1; x * x <= r; ++x) {
    long long temp = r - x * x - x - 1;
    if (temp > 0 && temp % (2 * x) == 0) {
      cout << x << ' ' << temp / 2 / x;
      return;
    }
  }
  cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
  freopen("in.txt", "r", stdin);
#endif
//  freopen("out.txt", "w", stdout);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test)
    cin >> test;

  for(int i = 0; i < test; ++i) {
//    cout << "Case #" << i + 1 << ": ";
    solve();
  }
#ifdef _LOCAL_
  cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}