#include <bits/stdc++.h>

using namespace std;

class modMatrix {
public:
  int n;
  int m;
  int mod;
  vector<vector<int>> a;

  modMatrix(int _n, int _m, int _mod) {
    n = _n;
    m = _m;
    mod = _mod;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      a[i].resize(m, 0);
    }
  }
  modMatrix operator * (modMatrix b) {
    if (mod != b.mod) {
      cout << "error the mods do not correspond (when wanting to multiply)\n";
      exit(0);
    }
    if (m != b.n) {
      cout << "error on (mod) matrix sizes (when wanting to multiply)\n";
      exit(0);
    }
    modMatrix c(n, m, mod);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < m; k++) {
          c.a[i][j] = (c.a[i][j] + (long long) a[i][k] * b.a[k][j]) % mod;
        }
      }
    }
    return c;
  }
  modMatrix operator ^ (long long p) {
    if (n != m) {
      cout << "error on (mod) matrix size (when wanting to rise to the power)\n";
      exit(0);
    }
    modMatrix c(n, m, mod), cur(n, m, mod);
    cur.a = a;
    for (int i = 0; i < n; i++) {
      c.a[i][i] = 1;
    }
    while (p) {
      if (p & 1) {
        c = c * cur;
      }
      cur = cur * cur;
      p /= 2;
    }
    return c;
  }
};

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
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

int f[3];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int c, ret = 1;
  long long n;
  cin >> n >> f[0] >> f[1] >> f[2] >> c;
  { /// this part is checked and correct
    modMatrix mlt(3, 3, M - 1);
    mlt.a[1][0] = mlt.a[2][1] = mlt.a[0][2] = mlt.a[1][2] = mlt.a[2][2] = 1;
    for (int pos = 0; pos < 3; pos++) {
      modMatrix init(1, 3, M - 1);
      init.a[0][pos] = 1;
      init = init * (mlt ^ (n - 1));
      ret = mul(ret, pw(f[pos], init.a[0][0]));
    }
  }
  { /// this part is also checked and correct
    modMatrix mlt(5, 5, M - 1);
    modMatrix init(1, 5, M - 1);
    mlt.a[1][0] = mlt.a[2][1] = mlt.a[0][2] = mlt.a[1][2] = mlt.a[2][2] = mlt.a[3][2] = mlt.a[3][3] = mlt.a[4][3] = mlt.a[4][4] = 1;
    init.a[0][3] = init.a[0][4] = 2;
    init = init * (mlt ^ (n - 1));
    ret = mul(ret, pw(c, init.a[0][0]));
  }
  cout << ret << "\n";
}