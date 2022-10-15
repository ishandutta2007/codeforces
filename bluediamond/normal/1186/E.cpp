#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
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

int nr(int n, int coef) {
  if (n == 0) {
    return (coef == 0);
  }
  if (n == 1) {
    return 1;
  }
  int lg = log2(n), m = (1 << lg);
  int x = (1 << (lg - 1)) + nr(n - m, coef ^ 1);
  return x;
}

int f(int n, int m) {
  int x = nr(n, 0), y = nr(m, 0);
  return x * (m + 1 - y) + y * (n + 1 - x);
}

const int N = 1000 + 7;
int n, m, q, a[N][N], suma[N][N];

int sum(int r1, int c1, int r2, int c2) {
  r1++;
  c1++;
  r2++;
  c2++;
  return suma[r2][c2] - suma[r1 - 1][c2] - suma[r2][c1 - 1] + suma[r1 - 1][c1 - 1];
}

int get(int r, int c) {
  r--;
  c--;
  if (r < 0 || c < 0) return 0;

  int ret = 0, li = r % n, lj = c % m, ff = r / n, ss = c / m;

  if (0 <= min(r, li) && 0 <= min(c, lj)) {
    int val = sum(0, 0, min(r, li), min(c, lj));
    int cx = ff;
    int cy = ss;
    int cnt = f(cx, cy);
    ret += cnt * ((min(r, li) + 1) * (min(c, lj) + 1) - val);
    ret += ((cx + 1) * (cy + 1) - cnt) * val;
  }

  if (li + 1 <= min(n - 1, r) && 0 <= min(lj, c)) {
    int val = sum(li + 1, 0, min(n - 1, r), min(lj, c));
    int cx = ff - 1;
    int cy = ss;
    int cnt = f(cx, cy);
    ret += cnt * ((min(n - 1, r) - li) * (min(lj, c) + 1) - val);
    ret += ((cx + 1) * (cy + 1) - cnt) * val;
  }

  if (0 <= min(r, li) && lj + 1 <= min(c, m - 1)) {
    int val = sum(0, lj + 1, min(r, li), min(c, m - 1));
    int cx = ff;
    int cy = ss - 1;
    int cnt = f(cx, cy);
    ret += cnt * ((min(r, li) + 1) * (min(c, m - 1) - lj) - val);
    ret += ((cx + 1) * (cy + 1) - cnt) * val;
  }

  if (li + 1 <= min(r, n - 1) && lj + 1 <= min(c, m - 1)) {
    int val = sum(li + 1, lj + 1, min(r, n - 1), min(c, m - 1));
    int cx = ff - 1;
    int cy = ss - 1;
    int cnt = f(cx, cy);
    ret += cnt * ((min(r, n - 1) - li) * (min(c, m - 1) - lj) - val);
    ret += ((cx + 1) * (cy + 1) - cnt) * val;
  }

  return ret;
}

signed realMain() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    int cur = 0;
    for (int j = 1; j <= m; j++) {
      a[i][j] = str[j - 1] - '0';
      cur += a[i][j];
      suma[i][j] = suma[i - 1][j] + cur;
    }
  }
  while (q--) {
    int r1, c1, r2, c2, ret;
    cin >> r1 >> c1 >> r2 >> c2;
    ret = get(r2, c2) - get(r1 - 1, c2) - get(r2, c1 - 1) + get(r1 - 1, c1 - 1);
    cout << ret << "\n";
  }
  return 0;
}