#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int long long
signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int rep(int x) {
  x %= M;
  if (x < 0) x += M;
  return x;
}

int add(int a, int b) {
  return rep(a + b);
}

int mul(int a, int b) {
  return rep(a * b);
}

void baga(int &a, int x) {
  a = rep(a + x);
}

const int N = (int) 2e5 + 7;
int n, q, p[N], w[N], aib[N], aib2[N];


int pref(int i) {
  int ret = 0;
  while (i) {
    ret += aib[i];
    i -= i & (-i);
  }
  return ret;
}

int get(int l, int r) {
  return pref(r) - pref(l - 1);
}

void add_aib2(int i, int x) {
  x = rep(x);
  x = mul(x, p[i]);
  while (i <= n) {
    aib2[i] = rep(aib2[i] + x);
    i += i & (-i);
  }
}

void add_aib(int i, int x) {
  add_aib2(i, x);
  while (i <= n) {
    aib[i] += x;
    i += i & (-i);
  }
}

int pref2(int i) {
  int ret = 0;
  while (i) {
    ret = rep(ret + aib2[i]);
    i -= i & (-i);
  }
  return ret;
}

int get2(int l, int r) {
  return rep(pref2(r) - pref2(l - 1));
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    p[i] = add(p[i], -i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    add_aib(i, w[i]);
  }
  while (q--) {
    int kek, lol;
    cin >> kek >> lol;
    if (kek < 0) {
      int id = -kek, nw = lol;
      add_aib(id, nw - w[id]);
      w[id] = nw;
    } else {
      int l = kek, r = lol;
      int total = get(l, r), cur = 0;
      int position = -1;
      int lo = l, hi = r;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (2 * get(l, mid) > total) {
          position = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      int ret = 0;
      baga(ret, -get2(l, position));
      baga(ret, get2(position + 1, r));
      baga(ret, mul(p[position], get(l, position) % M));
      baga(ret, mul(-p[position], get(position + 1, r) % M));
      cout << ret << "\n";
    }
  }
  return 0;
}