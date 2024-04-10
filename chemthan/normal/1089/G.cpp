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

void solve() {
  int test;
  cin >> test;
  vector<int> temp(7);
  while (test-- > 0) {
    int k; cin >> k;
    rep(j, 0, sz(temp)) cin >> temp[j];
    int total = (int)count(temp.begin(), temp.end(), 1);

    int res = inf;
    rep(j, 0, sz(temp)) if (temp[j]) {
      int sum = 0;
      int cur = 0;
      for (int i = j; i < sz(temp) && cur < k; ++i) {
        sum += 1;
        cur += temp[i];
      }
      if (k - cur - total >= total) {
        sum += ((k - cur - total) / total) * 7;
        cur += ((k - cur - total) / total) * total;
      }
      for (int i = 0; i < sz(temp) && cur < k; i = (i + 1) % 7) {
        sum += 1;
        cur += temp[i];
      }
      update_min(res, sum);
    }
    cout << res << '\n';
  }
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