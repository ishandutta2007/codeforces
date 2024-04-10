#include <bits/stdc++.h>

using namespace std;
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define debug(a) cerr << #a << ": " << (a) << '\n';
#define debug_arr(arr, n) { cerr << #arr << " "; rep(i, 0, n) cerr << arr[i] << " \n"[i == n]; }
#define debug_two(a, b) cerr << #a << ": " << (a) << ", " << #b << ": " << (b) << '\n';

template <typename num_t>
inline void addmod(num_t& a, const long long& b, const int& m) { a = (a + b) % m; if (a < 0) a += m; }
template <typename num_t>
inline void update_max(num_t& a, const num_t& b) { a = max(a, b); }
template <typename num_t>
inline void update_min(num_t& a, const num_t& b) { a = min(a, b); }
template <typename num_t>
num_t gcd(num_t lhs, num_t rhs) { return !lhs ? rhs : gcd(rhs % lhs, lhs); }
template <typename num_t>
num_t pw(num_t n, num_t k, num_t mod) {
  num_t res = 1; for (; k; k >>= 1) { if (k & 1) res = 1ll * res * n % mod; n = 1ll * n * n % mod; } return res;
}

typedef long long ll;
const int inf = 1e9 + 7;
const int mod = inf;
const int MAX_N = 500000 + 7;
const long long ll_inf = (ll)inf * inf;

class InverseModule {
public:
  static const int MOD = ::mod;
  static const int MAX_N = 1e6 + 7;

  int fact[MAX_N];
  int inv_fact[MAX_N];

  InverseModule() {
    fact[0] = inv_fact[0] = 1;

    for (int i = 1; i < MAX_N; ++i) {
      fact[i] = (long long) fact[i - 1] * i % MOD;
      inv_fact[i] = inverse(fact[i], MOD);
    }
  }

  int inverse(int x, int mod) {
    int r = mod, newr = x;
    int t = 0, newt = 1;
    while (newr > 0){
      int q = r / newr;
      int tmp = newr; newr = r % newr; r = tmp;
      tmp = newt; newt = t - q * newt; t = tmp;
    }
    if (t < 0) t += mod;
    return t;
  }

  int C(int n, int k) {
    return (ll) fact[n] * inv_fact[n - k] % MOD * inv_fact[k] % MOD;
  }

  long long pw(long long x, long long k, const long long& mod = MOD) {
    if (!k) return 1;
    else if (k & 1) return pw(x, k ^ 1) * x % mod;
    long long tmp = pw(x, k >> 1);
    return tmp * tmp % mod;
  }

  pair<int, int> extended_euclid(int a, int b) {
    int s0 = 1, t0 = 0;
    int s1 = 0, t1 = 1;
    while (b > 0) {
      int q = a / b;
      int tmp = 0;
      tmp = s1; s1 = s0 - q * s1; s0 = tmp;
      tmp = t1; t1 = t0 - q * t1; t0 = tmp;
      tmp = b; b = a - q * b; a = tmp;
    }
    return { s0, t0 };
  }

  int stirling_second_kind(int n, int k) {
    long long res = 0;
    for (int j = 0; j <= k; ++j) {
      long long temp = 1ll * C(k, j) * pw(j, n);

      if ((k - j) & 1)
        res = (res - temp + MOD) % MOD;
      else
        res = (res + temp) % MOD;
    }
    return res * inv_fact[k] % MOD;
  }
} inv;


void solve() {
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; ++i) if (n % i == 0 && gcd(i, n / i) == 1) {
    int u = i, v = n / i;
//    debug_two(u, v);
    auto p = inv.extended_euclid(u, v);
    p.first = -p.first;
    p.second = -p.second;
    if (p.second < 0) {
      int k = (1 - p.second + u - 1) / u;
      p.first -= k * v;
      p.second += k * u;
    }

//    debug_two(p.first, p.second);
    if (1ll * v * p.second + p.first * u + u * v != n - 1) continue;

    cout << "YES\n";
    cout << 2 << '\n';
    cout << p.second << ' ' << u << '\n';
    cout << p.first + v << ' ' << v << '\n';
    return;
  }
  cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
  freopen("in.txt", "r", stdin);
#endif
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test)
    cin >> test;

  for(int i = 0; i < test; ++i) {
    //printf("Case #%d: ", i + 1);
    solve();
  }
#ifdef _LOCAL_
  cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}