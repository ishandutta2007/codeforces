#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int pw(int a, int b, int mod) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % mod;
    }
    a = (ll) a * a % mod;
    b /= 2;
  }
  return r;
}

int dv(int a, int b, int mod) {
  return (ll) a * pw(b, mod - 2, mod) % mod;
}

const int C = 3;
const int mods[] = {1000000271, 1000000787, 1000000931};

struct T {
  int a[C];
  T(int x = 0) {
    for (int j = 0; j < C; j++) {
      a[j] = x;
    }
  }
};

bool operator < (T f, T s) {
  for (int i = 0; i < C; i++) {
    if (f.a[i] != s.a[i]) {
      return f.a[i] < s.a[i];
    }
  }
  return 0;
}

T operator + (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] += s.a[j];
    if (f.a[j] >= mods[j]) {
      f.a[j] -= mods[j];
    }
  }
  return f;
}

T operator - (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] -= s.a[j];
    if (f.a[j] < 0) {
      f.a[j] += mods[j];
    }
  }
  return f;
}

T operator * (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] = (ll) f.a[j] * s.a[j] % mods[j];
  }
  return f;
}

T operator ^ (T f, int x) {
  for (int j = 0; j < C; j++) {
    f.a[j] = pw(f.a[j], x, mods[j]);
  }
  return f;
}

T operator / (T f, T s) {
  for (int j = 0; j < C; j++) {
    f.a[j] = dv(f.a[j], s.a[j], mods[j]);
  }
  return f;
}

bool operator == (T f, T s) {
  for (int j = 0; j < C; j++) {
    if (f.a[j] != s.a[j]) {
      return 0;
    }
  }
  return 1;
}

struct H {
  T value;
  int cnt;
  H() {
    cnt = 0;
  }
};


const int N = 200000 + 7;
const int B = 696969;
int n;
int m;
int a[N];
int b[N];
int p[N];
T power[N];

H operator + (H a, H b) {
  if (a.cnt == 0) {
    return b;
  }
  if (b.cnt == 0) {
    return a;
  }
  T v = a.value + b.value * power[a.cnt];
  int cnt = a.cnt + b.cnt;
  a.value = v;
  a.cnt = cnt;
  return a;
}

H t[4 * N];

void upd(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    t[v].value = x;
    t[v].cnt = (x > 0);
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, x);
  upd(2 * v + 1, tm + 1, tr, i, x);
  t[v] = t[2 * v] + t[2 * v + 1];
}


void upd(int i, int x) {
  upd(1, 1, m, i, x);
}

T get() {
  return t[1].value;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  T h = 0, coefs = 0;
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * B;
  }

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    T coef = power[i - 1];
    coefs = coefs + coef;
    h = h + coef * a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    p[b[i]] = i;
  }
  /// is a[1] + x, a[2] + x, ..., a[n] + x a subsequence?
  /// the one with the smallest position must be equal to a[1] + x
  /// the one with the second smallest position must be equal to a[2] + x
  /// ...
  /// the one with the biggest position must be equal to a[n] + x
  /// we are using a hash that maps us (position[x], x)
  int sol = 0;
  for (int x = 0; x <= m - n; x++) {
    if (x == 0) {
      for (int j = 1; j <= n; j++) {
        upd(p[j], j);
      }
    } else {
      h = h + coefs;
      upd(p[x], 0);
      upd(p[x + n], x + n);
    }
    sol += (get() == h);
  }
  cout << sol << "\n";
}