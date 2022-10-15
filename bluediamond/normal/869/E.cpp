#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rng((long long) (new char));

ll get2() {
  return (ll) rng() * rng();
}

ll get() {
  return get2() ^ get2();
}

const int N = 2500 + 7;
const int Q = 100000 + 7;

int n, m, q;
ll t[N][N];
map<vector<int>, ll> tr;

ll get(int r, int c) {
  ll sol = 0;
  for (int i = r; i >= 1; i -= i & (-i)) {
    for (int j = c; j >= 1; j -= j & (-j)) {
      sol ^= t[i][j];
    }
  }
  return sol;
}

void addup(int r, int c, ll x) {
  for (int i = r; i <= n; i += i & (-i)) {
    for (int j = c; j <= m; j += j & (-j)) {
      t[i][j] ^= x;
    }
  }
}

void addup(int r1, int c1, int r2, int c2, ll x) {
  r1++;
  c1++;
  r2++;
  c2++;
  addup(r2, c2, x);
  addup(r2, c1 - 1, x);
  addup(r1 - 1, c2, x);
  addup(r1 - 1, c1 - 1, x);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> q;
  while (q--) {
    int tp;
    cin >> tp;
    if (tp <= 2) {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      if (!tr.count({r1, c1, r2, c2})) {
        tr[{r1, c1, r2, c2}] = get();
      }
      addup(r1, c1, r2, c2, tr[{r1, c1, r2, c2}]);
    } else {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      cout << ((get(r1, c1) == get(r2, c2)) ? "Yes" : "No") << "\n";
    }
  }

  return 0;
}