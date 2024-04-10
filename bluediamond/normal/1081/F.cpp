#include <bits/stdc++.h>

using namespace std;

#define f(x) (2 * x - n)

const int N = 300 + 7;
int n, t, ret[N], suf[N];

int query(int l, int r) {
  cout << "? " << l << " " << r << endl;
  int sol;
  cin >> sol;
  return f(sol);
}

void fun(int pos) {
  for (int j = 1; j <= 30; j++) {
    int x = query(pos + 1, n);
    if (x == -t) {
      t *= -1;
    } else {
      int t_prim = x, t1 = (t + t_prim) / 2, t2 = t - t1;
      if (j % 2 == 1) {
        suf[pos + 1] = t2;
        t = query(pos + 1, n);
      } else {
        suf[pos + 1] = -t2;
        t = x;
      }
      return;
    }
  }
  suf[pos + 1] = t;
}

int main() {
  cin >> n >> t;
  /// we make the transition (0, 1) -> (0, 2) -> (-1, +1)
  t = f(t);
  suf[1] = t;
  for (int pos = 1; pos <= n - 1; pos++) {
    /// [1, n] or [pos+1, n]
    fun(pos);
  }
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    int here = suf[i] - suf[i + 1];
    if (here == -1) {
      here = 0;
    }
    cout << here;
  }
  cout << endl;
  return 0;
}