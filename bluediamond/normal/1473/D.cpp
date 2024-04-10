#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N = (int) 2e5 + 7;
const int INF = (int) 1e9;

struct T {
  int mn;
  int mx;
  int sum;
};

T e;

T operator + (T a, T b) {
  if (a.sum == -INF) return b;
  if (b.sum == -INF) return a;
  int mn = min(a.mn, a.sum + b.mn);
  int mx = max(a.mx, a.sum + b.mx);
  int sum = a.sum + b.sum;
  return {mn, mx, sum};
}

T t[4 * N];
int n;
int q;
int a[N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = {min(0LL, a[tl]), max(0LL, a[tr]), a[tl]};
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return e;
  if (l <= tl && tr <= r) {
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  e.sum = -INF;

  ///freopen ("input", "r", stdin);


  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> n >> q >> s;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == '+') {
        a[i] = +1;
      } else {
        a[i] = -1;
      }
    }
    build(1, 1, n);
    for (int it = 1; it <= q; it++) {
      int l, r;
      cin >> l >> r;
      T a, b;
      a = get(1, 1, n, 1, l - 1);
      b = get(1, 1, n, r + 1, n);
      T c = a + b;
      cout << c.mx - c.mn + 1 << "\n";
    }
  }

}