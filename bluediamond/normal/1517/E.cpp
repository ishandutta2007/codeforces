#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

set<int> s;
const int N = 200000 + 7;
const int M = 998244353;

int n;
int a[N], pre[2][N], total[N];

int getsumx(int mod, int l, int r) {
  if (l > r) return 0;
  return pre[mod][r] - pre[mod][l - 1];
}

int get(int pre, int fin) {
  int in = 0;
  in = getsumx((pre + 2) % 2, pre + 2, fin + 1);
  if (fin + 2 <= n) {
    in += total[n] - total[fin + 1];
  }
  return in;
}

int megasmart(int nn, int vec[]) {
  n = nn;
  int sol = 0;
  int lim = 0;
  for (int i = 0; i < n; i++) {
    a[i] = vec[i + 1];
    lim += a[i];
  }
  reverse(a, a + n);
  for (int i = 1; i <= n; i++) {
    for (int m = 0; m <= 1; m++) {
      pre[m][i] = pre[m][i - 1];
    }
    pre[i % 2][i] += a[i - 1];
    total[i] = total[i - 1] + a[i - 1];
  }
  lim--;
  lim /= 2;
  for (int it = 0; it < 2; it++) {
    for (int pre = it; pre < n; pre++) {
      int lo = 0, hi = (n - 1 - pre) / 2, first = n + 1;
      while (lo <= hi) {
        int j = (lo + hi) / 2;
        int fin = pre + 2 * j;
        bool ok = 0;
        if (get(pre, fin) <= lim) {
          ok = 1;
        }
        if (ok) {
          first = j;
          hi = j - 1;
        } else {
          lo = j + 1;
        }
      }
      hi = (n - 1 - pre) / 2;
      if (first <= hi) {
        sol += hi - first + 1;
      }
      if (n - 4 - pre >= 0) {
        lo = 0, hi = (n - 4 - pre) / 2;
        first = n + 1;
        while (lo <= hi) {
          int j = (lo + hi) / 2;
          int fin = pre + 2 * j;
          bool ok = 0;
          if (get(pre, fin) - a[n - 1] <= lim) {
            ok = 1;
          }
          if (ok) {
            first = j;
            hi = j - 1;
          } else {
            lo = j + 1;
          }
        }
        hi = (n - 4 - pre) / 2;
        if (first <= hi) {
          sol += hi - first + 1;
        }
      }
    }
    lim -= a[0];
  }
  lim += 2 * a[0];
  {
    int in = a[0];
    for (int i = 1; i < n; i++) {
      in += a[i];
      sol += (in <= lim);
    }
  }
  return sol % M;
}

int vec[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1LL; i <= n; i++) {
      cin >> vec[i];
    }
    cout << megasmart(n, vec) << "\n";
  }
  return 0;
}