#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

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

struct Fraction {
  ll a;
  ll b;
  ll sgn;
};

Fraction get(ll a, ll b) {
  if (a == 0) {
    return {0, 1, 1};
  }
  int sgn = 1;
  if (a < 0) {
    a *= -1;
    b *= -1;
  }
  if (b < 0) {
    sgn = -1;
    b *= -1;
  }
  if (b == 0) {
    return {0, 0, 2};
  }
  assert(a > 0 && b > 0);
  int g = __gcd(a, b);
  a /= g;
  b /= g;
  return {a, b, sgn};
}

bool operator == (Fraction x, Fraction y) {
  return (ll) x.sgn * x.a * y.b == (ll) y.sgn * y.a * x.b;
}

bool operator < (Fraction x, Fraction y) {
  return (ll) x.sgn * x.a * y.b < (ll) y.sgn * y.a * x.b;
}

pair<Fraction, Fraction> get(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) {
  return {get(c2 * b1 - c1 * b2, a1 * b2 - a2 * b1), get(c2 * a1 - c1 * a2, b1 * a2 - b2 * a1)};
}


const int N = (int) 1e5 + 7;
int a[N], b[N], c[N];
vector<pair<int, int>> points;

pair<Fraction, Fraction> getx(int i, int j) {
  return get(a[i], b[i], c[i], a[j], b[j], c[j]);
}

bool cmp(pair<vector<int>, pair<int, int>> a, pair<vector<int>, pair<int, int>> b) {
  return (int) a.first.size() < (int) b.first.size();
}

struct T {
  pair<Fraction, Fraction> a;
  int x, y;
};

bool operator < (T f, T s) {
  return f.a < s.a;
}


void rec(int k, vector<int>& ids) {
  if ((int) ids.size() <= k) {
    for (auto &i : ids) {
      points.push_back({i, -1});
    }
    cout << "YES\n";
    cout << (int) points.size() << "\n";
    for (auto &it : points) {
      cout << it.first << " " << it.second << "\n";
    }
    exit(0);
  }
  if (!k) return;
  int n = (int) ids.size(), m = n, min_del = (n + k - 1) / k; /// cel putin unul trebuie sa stearga mai mult de min_del
  if (k * k < n) {
    m = k * k + 1;
    min_del = k + 1;
    /// cel putin unul trebuie sa stearga mai mult de min_del
  }
  set<pair<Fraction, Fraction>> pts;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      auto it = getx(ids[i], ids[j]);
      if (it.first.sgn == 2 || it.second.sgn == 2) {
        continue;
      }
      if (pts.count(it)) {
        continue;
      }
      pts.insert(it);

      int aici = 2;
      for (int p = j + 1; p < m; p++) {
        if (getx(ids[i], ids[p]) == it) {
          aici++;
        }
      }
      if (aici >= min_del) {
        vector<int> urm;
        for (auto &k : ids) {
          if (k == ids[i] || k == ids[j]) continue;
          if (!(it == getx(k, ids[i]))) {
            urm.push_back(k);
          }
        }
        points.push_back({ids[i], ids[j]});
        rec(k - 1, urm);
        points.pop_back();
        if (n > k * k) {
          return;
        }
      }
    }
  }

}

signed realMain() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<int> ids(n); iota(ids.begin(), ids.end(), 1);
  rec(k, ids);
  cout << "NO\n";
  return 0;
}