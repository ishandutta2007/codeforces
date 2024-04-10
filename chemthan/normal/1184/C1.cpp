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


bool check(const vector<pair<int, int>>& points, int idx) {
  int low_x = inf, low_y = inf, high_x = -1, high_y = -1;
  rep(i, 0, sz(points)) if (i != idx) {
    auto p = points[i];
    update_min(low_x, p.first);
    update_max(high_x, p.first);
    update_min(low_y, p.second);
    update_max(high_y, p.second);
  }
  if (high_x - low_x != high_y - low_y)
    return false;
  rep(i, 0, sz(points)) if (i != idx) {
    auto p = points[i];
    if (p.first == low_x || p.first == high_x) {
      if (p.second > high_y || p.second < low_y)
        return false;
    } else if (p.second == low_y || p.second == high_y) {
      if (p.first < low_x || p.first > high_x)
        return false;
    } else return false;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> points(4 * n + 1);
  for (auto&p : points)
    cin >> p.first >> p.second;

  rep(i, 0, sz(points)) if (check(points, i)) {
    cout << points[i].first << ' ' << points[i].second << '\n';
    break;
  }
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