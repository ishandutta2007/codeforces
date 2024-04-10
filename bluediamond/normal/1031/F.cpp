#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

class linearSieve { /// linear Sieve
public:
  vector<int> primes;
  vector<int> lp;
  void put(int Limit) {
    primes.clear();
    lp.clear();
    lp.resize(Limit + 1, 0);
    for (int i = 2; i <= Limit; i++) {
      if (!lp[i]) {
        lp[i] = i;
        primes.push_back(i);
      }
      for (int j = 0; j < (int) primes.size() && primes[j] * i <= Limit && primes[j] <= lp[i]; j++) {
        lp[primes[j] * i] = primes[j];
      }
    }
  }
} user;

bool is_prime(int n) {
  if (n <= 1) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

const int N = 10000;
const int C = 500;
int dp[C][N], y, mxp;
queue<int> q[C];

map<vector<int>, int> id;
vector<int> primes;

int cnt = 0;
vector<int> v;

void gen(int sum = 29, int limit = (int) 1e9, ll cur = 1, int prod = 1) {
  if (prod >= C) return;
  cnt++;
  /**cout << cnt << " : ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";**/
  id[v] = ++y;
  q[prod].push(id[v]);
  dp[prod][id[v]] = 0;
  mxp = max(mxp, prod);
  for (int j = 1; j <= min(sum, limit) && (ll) cur * primes[(int) v.size()] <= (ll) 1e18; j++) {
    cur *= primes[(int) v.size()];
    v.push_back(j);
    gen(sum - j, j, cur, prod * (j + 1));
    v.pop_back();
  }
}

vector<int> so(vector<int> v) {
  assert(!v.empty());
  sort(v.rbegin(), v.rend());
  if (v.back() == 0) v.pop_back();
  return v;
}

vector<vector<int>> states(vector<int> v) {
  vector<vector<int>> ret;
  v.push_back(1);
  if (id.count(v)) ret.push_back(v);
  v.pop_back();
  for (int i = 0; i < (int) v.size(); i++) {
    if (i == 0 || (i > 0 && v[i] != v[i - 1])) {
      vector<int> v2(v), v3;
      v2[i]++;
      v3 = so(v2);
      if (id.count(v3)) ret.push_back(v3);
      v2[i] -= 2;
      v3 = so(v2);
      if (id.count(v3)) ret.push_back(v3);
    }
  }
  return ret;
}

vector<int> fo(int x) {
  vector<int> ret;
  while (x > 1) {
    int p = user.lp[x], cnt = 0;
    while (x % p == 0) {
      x /= p;
      cnt++;
    }
    ret.push_back(cnt);
  }
  sort(ret.rbegin(), ret.rend());
  return ret;
}

void print(vector<int> a) {
  for (auto &it : a) cout << it << " ";
  cout << "\n";
}

vector<int> sts[N];

signed realMain() {
  for (int i = 0; i < C; i++) for (int j = 0; j < N; j++) dp[i][j] = (int) 1e9;
  user.put((int) 1e6 + 7);
  for (int i = 1; i <= 10000; i++) if (is_prime(i)) primes.push_back(i);
  gen(); assert(y < N);
  for (auto &it : id) {
    auto kek = states(it.first);
    for (auto &v : kek) {
      sts[it.second].push_back(id[v]);
    }
  }
  for (int c = 1; c < C; c++) {
    while (!q[c].empty()) {
      auto it = q[c].front();
      q[c].pop();
      for (auto &vec : sts[it]) {
        int relax = dp[c][it] + 1;
        if (dp[c][vec] == (int) 1e9) {
          dp[c][vec] = relax;
          q[c].push(vec);
        }
      }
    }
  }

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int a, b;
    cin >> a >> b;
    vector<int> x = fo(a), y = fo(b);
    assert(id.count(x));
    assert(id.count(y));
    a = id[x];
    b = id[y];
    int best = (int) 1e9;
    for (int j = 0; j < C; j++) {
      best = min(best, dp[j][a] + dp[j][b]);
    }
    cout << best << "\n";
  }
  return 0;
}