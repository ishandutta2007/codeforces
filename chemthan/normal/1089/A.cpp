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
const int MAX_N = 200 + 7;
const long long ll_inf = (ll)inf * inf;


int dp[6][6][MAX_N][MAX_N];

void check_max(int cnt, vector<pair<int, int>> trans) {
  rep(i, 0, MAX_N) rep(j, 0, MAX_N) rep(k, 0, min(cnt + 1, 4)) {
    dp[cnt][k][i][j] = -inf;
    for (const auto& p : trans) {
      if (k) {
        if (i >= p.first && j >= p.second) {
          int temp = dp[cnt - 1][k - 1][i - p.first][j - p.second];
          if (cnt - 1 - (k - 1) < 3) {
            update_max(dp[cnt][k][i][j], temp);
          }
        }
      }
      if (i >= p.second && j >= p.first) {
        int temp = dp[cnt - 1][k][i - p.second][j - p.first];
        if (k < 3 && cnt - 1 - k < 3) {
          update_max(dp[cnt][k][i][j], temp);
        }
      }
    }
  }
}

vector<pair<int, int>> sets;
vector<pair<int, int>> last_sets;

void trace(const int n, const int u, const int v, const int k, const vector<pair<int, int>>& trans, vector<pair<int, int>>& res) {
  if (!n) return;
  for (const auto& p : trans) {
    if (k) {
      if (u >= p.first && v >= p.second) {
        int temp = dp[n - 1][k - 1][u - p.first][v - p.second];
//        cout << n - 1 << ' ' << k - 1 << ' ' << u - p.first << ' ' << v - p.second << endl;
        if (temp == 1 && n - 1 - (k - 1) < 3) {
          trace(n - 1, u - p.first, v - p.second, k - 1, sets, res);
          res.push_back(p);
          return;
        }
      }
    }
    if (u >= p.second && v >= p.first) {
      int temp = dp[n - 1][k][u - p.second][v - p.first];
//      cout << n - 1 << ' ' << k << ' ' << u - p.first << ' ' << v - p.second << ' ' << temp << endl;
      if (temp == 1 && k < 3 && n - 1 - k < 3) {
        trace(n - 1, u - p.second, v - p.first, k, sets, res);
        res.push_back({ p.second, p.first });
        return;
      }
    }
  }
  assert(true);
}

void query(int u, int v) {
  int n = 0, k = -inf;
  rep(i, 3, 6) rep(j, 0, 4) {
    if (dp[i][j][u][v] == 1) {
      if (j != 3 && i - j != 3) continue;
      if (n == 0 || 2 * j - i > 2 * k - n) {
        n = i;
        k = j;
      } 
    }
  } 
  if (n == 0 || dp[n][k][u][v] < 0) {
    cout << "Impossible\n"; return;
  }
  cout << k << ':' << n - k << '\n';
  vector<pair<int, int>> res;
  if (n == 5) trace(n, u, v, k, last_sets, res);
  else trace(n, u, v, k, sets, res);
  for (auto p : res) {
    cout << p.first << ':' << p.second << ' ';
  }
  cout << '\n';
}

void solve() {
  rep(i, 25, MAX_N) rep(j, 0, MAX_N) if ((i == 25 && j <= i - 2) || (i == j + 2)) {
    sets.push_back({ i, j });
  }
  rep(i, 15, MAX_N) rep(j, 0, MAX_N) if ((i == 15 && j <= i - 2) || (i == j + 2)) {
    last_sets.push_back({ i, j });
  }

  rep(i, 0, MAX_N) rep(k, 0, 6) rep(j, 0, MAX_N) dp[0][k][i][j] = -inf;
  dp[0][0][0][0] = 1;
  rep(j, 1, 5) check_max(j, sets);
  check_max(5, last_sets);
//  return;

  int test;
  cin >> test;
  while (test-- > 0) {
    int u, v; cin >> u >> v;
    query(u, v);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  const bool multiple_test = false;
  int test = 1;
  if (multiple_test)
    cin >> test;

  for(int i = 0; i < test; ++i) {
    //printf("Case #%d: ", i + 1);
    solve();
  }
}