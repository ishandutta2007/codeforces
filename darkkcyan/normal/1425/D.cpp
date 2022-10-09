
#pragma GCC diagnostic warning "-Wconversion"
#pragma GCC diagnostic warning "-Wshadow"
#pragma GCC diagnostic warning "-Wunused-variable"
#include <bits/stdc++.h>

using namespace std;

#define db(i) "[" << #i << " = " << (i) << "] "
#define clog if(0) cerr

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int maxn = 2010;
const ll mod = (ll) 1e9 + 7;
const int max_val = 1010;

ll mpow(ll base, ll exp) {
  ll ans = 1;
  for (; exp > 0; exp >>= 1) {
    if (exp & 1) (ans *= base) %= mod;
    (base *= base) %= mod;
  }
  return ans;
}

ll fac[maxn], ifac[maxn];
void cal_fac() {
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fac[i] = fac[i - 1] * i % mod;
    ifac[i] = mpow(fac[i], mod - 2);
  }
}

ll choose(int n, int k) {
  if (k < 0 or n < 0 or k > n) return 0;
  return fac[n] * ifac[k] % mod * ifac[n - k] % mod;
}

int n, m, radius;
int r[maxn], c[maxn];
ll b[maxn];

mt19937 rng(177013);
#define rand() (int)(rng() >> 1)

//#define testing
void read() {
#ifndef testing
  cin >> n >> m >> radius;
    for (int i = 0; i < n; ++i) {
        cin >> r[i] >> c[i] >> b[i];
    }
#else
  n = rand() % 5 + 1;
  m = rand() % n + 1;
  radius = rand() % 10;

  set<pair<int, int>> has;
  for (int i = 0; i < n; ++i) {
    do {
      r[i] = rand() % 10 + 1;
      c[i] = rand() % 10 + 1;
      b[i] = rand() % 10 + 1;
    } while (has.count({r[i], c[i]}));
    has.emplace(r[i], c[i]);
  }

  ofstream inp("main.inp");
  inp << n << ' ' << m << ' ' << radius << '\n';
  for (int i = 0; i < n; ++i) {
    inp << r[i] << ' ' << c[i] << ' ' << b[i] << '\n';
  }
#endif
}

ll solve() {
  vector<ll> coef(n + 10);
  for (int cnt = 0; cnt < (int)coef.size(); ++cnt) {
    for (int i = 1; i <= n; ++i) {
      coef[cnt] += choose(cnt, i) * choose(n - cnt, m - i) % mod;
      if (coef[cnt] >= mod) coef[cnt] -= mod;
    }
  }

  vector<vector<int>> pref_sum(max_val * 2 + 10, vector<int>(max_val * 2 + 10));

  for (int i = 0; i < n; ++i) {
    pref_sum[r[i]][c[i]]++;
  }

  for (int i = 1; i < (int)pref_sum.size(); ++i) {
    for (int f = 1; f < (int)pref_sum[i].size(); ++f) {
      pref_sum[i][f] += pref_sum[i - 1][f] + pref_sum[i][f - 1] - pref_sum[i - 1][f - 1];
    }
  }

  auto get_pref_sum = [&](int i, int f) {
    if (i < 0 or i >= (int)pref_sum.size()) return 0;
    if (f < 0 or f >= (int)pref_sum[0].size()) return 0;
    return pref_sum[i][f];
  };

  auto get_sum = [&](int r1, int c1, int r2, int c2) {
    if (r1 > r2) return 0;
    if (c1 > c2) return 0;
    return get_pref_sum(r2, c2) - get_pref_sum(r1 - 1, c2) - get_pref_sum(r2, c1 - 1) + get_pref_sum(r1 - 1, c1 - 1);
  };

  vector<int> cnt_cover(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int cnt = get_sum(r[i] - radius, c[i] - radius, r[i] + radius, c[i] + radius);
    clog << db(i) << db(cnt) << endl;
    ll cost = b[i] * b[i] % mod;
    ll total = cost * coef[cnt] % mod;
    cnt_cover[i] = cnt;
    ans += total;
    if (ans >= mod) ans -= mod;
  }

  for (int i = 0; i < n; ++i) {
    for (int f = i + 1; f < n; ++f) {
      ll cur_cost = 2 * b[i] * b[f] % mod;
      int intersection = get_sum(
          max(r[i], r[f]) - radius,
          max(c[i], c[f]) - radius,
          min(r[i], r[f]) + radius,
          min(c[i], c[f]) + radius
      );
      clog << db(i) << db(f) << db(intersection) << endl;
      int uniq_i = cnt_cover[i] - intersection;
      int uniq_f = cnt_cover[f] - intersection;
      int none = n - uniq_i - uniq_f - intersection;

      ll choose_none = choose(none, m);
      ll choose_none_i = choose(none + uniq_i, m);
      ll choose_none_f = choose(none + uniq_f, m);

      ll total = choose(n, m) - (choose_none_i + choose_none_f - choose_none);
      total %= mod;
      if (total < 0) total += mod;

      ans += total * cur_cost % mod;
      if (ans >= mod) ans -= mod;
    }
  }

  return ans;
}

ll brute() {
  ll ans = 0;
  vector<int> picked;
  function<void(int)> process = [&](int i) {
    if ((int)picked.size() == m) {
//      cout << "==" << endl;
//      for (auto p: picked) cout << p << ' ';
//      cout << endl;

      ll cost = 0;
      for (int f = 0; f < n; ++f) {
        bool covered = false;
        for (auto p: picked) {
          if (max(abs(r[f] - r[p]), abs(c[f] - c[p])) <= radius) {
            covered = true;
            break;
          }
        }
        if (covered) {
          cost += b[f];
//          cout << f << ' ';
        }
      }
//      cout << endl;
//      cout << cost << ' ' << cost * cost << endl;
      ans += cost * cost % mod;
      if (ans >= mod) ans -= mod;
      return ;
    }
    if (i == n) return ;
    process(i + 1);
    picked.push_back(i);
    process(i + 1);
    picked.pop_back();
  };
  process(0);
  return ans;
}

int main() {
  cal_fac();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#ifdef testing
  while (true) {
    read();
    ll ans = solve();
    ll expected = brute();
    if (ans != expected) {
      cout << "FAILED " << ans << ' ' << expected << endl;
      return 0;
    }
    cout << "OK" << endl;
  }
#else
  read();
    cout << solve() << '\n';
#endif

  return 0;
}