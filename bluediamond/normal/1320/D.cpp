#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = (int) 1e9 + 21;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, mod - 2));
}

struct T {
  bool first;
  bool last;
  int h;
  int len;
};

T joint(T a, T b) {
  if (a.len == 0) return b;
  if (b.len == 0) return a;
  if (a.last && b.first) {
    a.last = 0;
    b.first = 0;
    a.len--;
    b.len--;
    a.h = add(a.h, -pw(2, a.len));
    b.h = add(b.h, -1);
    b.h = dv(b.h, 2);
  }
  if (a.len == 0) a.first = 0;
  if (b.len == 0) b.last = 0;
  int h = add(a.h, mul(pw(2, a.len), b.h));
  return {a.first, b.last, h, a.len + b.len};
}

const int N = (int) 2e5 + 7;
T t[4 * N];
int is[N];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = {is[tl], is[tl], is[tl], 1};
  } else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    t[v] = joint(t[2 * v], t[2 * v + 1]);
  }
}

bool operator == (T a, T b) {
  return a.len == b.len && a.h == b.h && a.first == b.first && a.last == b.last;
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    return {0, 0, 0, 0};
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return joint(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int len;

T get(int l, int r) {
  return get(1, 1, len, l, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> len >> s;
  for (int i = 1; i <= len; i++) {
    is[i] = s[i - 1] - '0';
  }
  build(1, 1, len);
  int q;
  cin >> q;
  while (q--) {
    int p1, p2, len;
    cin >> p1 >> p2 >> len;
    T a = get(p1, p1 + len - 1);
    T b = get(p2, p2 + len - 1);
    if (a == b) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}