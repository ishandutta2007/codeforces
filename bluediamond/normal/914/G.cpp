#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
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
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

const int N = (int) 1e6 + 7;
const int A = 1 << 17;
int n, v[N], f[A];

void fftAND(int a[], int lim, bool inv) {
  for (int l = 2; l <= lim; l *= 2) {
    for (int i = 0; i < lim; i += l) {
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j], y = a[i + j + l / 2];
        if (!inv) {
          a[i + j] = add(0, -add(x, y));
          a[i + j + l / 2] = add(0, -y);
        } else {
          a[i + j] = add(y, -x);
          a[i + j + l / 2] = add(0, -y);
        }
      }
    }
  }
}

void multAND(int a[], int b[], int c[], int lim) {
  fftAND(a, lim, 0);
  fftAND(b, lim, 0);
  for (int i = 0; i < lim; i++) {
    c[i] = mul(a[i], b[i]);
  }
  fftAND(c, lim, 1);
}

void fftXOR(int a[], int lim, bool inv) {
  for (int l = 2; l <= lim; l *= 2) {
    for (int i = 0; i < lim; i += l) {
      for (int j = 0; j < l / 2; j++) {
        int x = a[i + j], y = a[i + j + l / 2];
        a[i + j] = add(x, y);
        a[i + j + l / 2] = add(x, -y);
      }
    }
  }
  if (inv) {
    int invn = dv(1, lim);
    for (int i = 0; i < lim; i++) {
      a[i] = mul(a[i], invn);
    }
  }
}

void multXOR(int a[], int b[], int c[], int lim) {
  fftXOR(a, lim, 0);
  fftXOR(b, lim, 0);
  for (int i = 0; i < lim; i++) {
    c[i] = mul(a[i], b[i]);
  }
  fftXOR(c, lim, 1);
}

int k1[A], k2[A], k3[A], k4[A], k5[A];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  f[1] = 1;
  for (int i = 2; i < A; i++) {
    f[i] = add(f[i - 1], f[i - 2]);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    k3[v[i]]++;
  }

  for (int m = 0; m < A; m++) {
    if (!k3[m]) continue;
    int inv = A - 1 - m, m2 = inv;
    vector<int> all = {m2};
    while (m2) {
      m2 = (m2 - 1) & inv;
      all.push_back(m2);
    }
    for (auto &m2 : all) {
      addup(k1[m | m2], mul(k3[m], k3[m2]));
    }
  }


  int sol = 0;


  for (int c = 1; c <= n; c++) {
    addup(k2[v[c]], 1);
  }

  for (int i = 0; i < A; i++) {
    k1[i] = mul(k1[i], f[i]);
    k2[i] = mul(k2[i], f[i]);
  }

  multAND(k1, k2, k3, A);

  for (int i = 0; i < A; i++) {
    k2[i] = 0;
  }

  for (int d = 1; d <= n; d++) {
    addup(k4[v[d]], 1);
    addup(k5[v[d]], 1);
  }

  multXOR(k4, k5, k2, A);


  for (int i = 0; i < A; i++) {
    k2[i] = mul(k2[i], f[i]);
  }

  multAND(k2, k3, k1, A);


  for (int bit = 0; (1 << bit) < A; bit++) {
    sol = add(sol, k1[1 << bit]);
  }

  cout << sol << "\n";

  return 0;
}