#include <bits/stdc++.h>; iron man

using namespace std;

///#define int ll
typedef long long ll;
typedef long double ld;

mt19937 rng((long long) (new char));

int pop(ll x) {
  return __builtin_popcountll(x);
}

const int N = (int) 2e5 + 7;
int n, m, p, need;
ll a[N], sol, id[60], f[1 << 15];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> p;
  need = (n + 1) / 2;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        a[i] += (1LL << j);
      }
    }
  }

  for (int step = 1; step <= 40; step++) {
    int p1 = rng() % n + 1, p2 = rng() % n + 1;
    assert(1 <= p1 && p1 <= n);
    assert(1 <= p2 && p2 <= n);
    ll value = (a[p1] & a[p2]);
    for (int j = 0; j < m; j++) {
      id[j] = -1;
    }
    int bits = 0;
    for (int j = 0; j < m; j++) {
      if (value & (1LL << j)) {
        id[j] = bits++;
      }
    }
    assert(bits <= p);
    for (int j = 0; j < (1 << p); j++) {
      f[j] = 0;
    }
    for (int i = 1; i <= n; i++) {
      ll com = (a[i] & value);
      int mask = 0;
      for (int j = 0; j < m; j++) {
        if (com & (1LL << j)) {
          if (id[j] == -1) {
            assert(0);
          }
          mask += (1 << id[j]);
        }
      }
      f[mask]++;
    }
    for (int bit = 0; bit < p; bit++) {
      for (int j = 0; j < (1 << p); j++) {
        if (j & (1 << bit)) {
          f[j ^ (1 << bit)] += f[j];
        }
      }
    }
    ///cout << " = " << f[0] << "\n";
    for (int j = 0; j < (1 << p); j++) {
      if (f[j] >= need && pop(j) > pop(sol)) {
        sol = 0;
        for (int bit = 0; bit < m; bit++) {
          if (id[bit] == -1) continue;
          if (j & (1 << id[bit])) sol += (1LL << bit);
        }
      }
    }
  }

 /// cout << pop(sol) << " : ";

  for (int j = 0; j < m; j++) {
    if (sol & (1LL << j)) {
      cout << 1;
    } else {
      cout << 0;
    }
  }
  cout << "\n";

  return 0;
}