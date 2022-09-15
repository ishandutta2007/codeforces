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

int n, k;
vector<vector<int>> jobs;
vector<int> a, b;

void solve() {
  cin >> n >> k;
  jobs.resize(k);
  a.resize(n); b.resize(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) {
    jobs[a[i] - 1].push_back(b[i]);
  }
  int needed = 0;
  vector<int> temp;
  rep(i, 0, k) {
    needed += jobs[i].empty();
    if (jobs[i].size() > 1) {
      sort(jobs[i].begin(), jobs[i].end());
      temp.insert(temp.end(), jobs[i].begin(), jobs[i].end() - 1);
    }
  }
  sort(temp.begin(), temp.end());
  long long res = 0;
  rep(i, 0, needed) res += temp[i];
  cout << res << '\n';
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