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

void addup(int &a, int b) {
  a = add(a, b);
}
void mulup(int &a, int b) {
  a = mul(a, b);
}

int cnt[8], dp[1 << 7], coefs[1 << 7][1 << 7], ways[2], nways[2], ndp[1 << 7];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  dp[0] = 1;

  for (int l = 1; l <= 7; l++) {

    int sz = (1 << l);

    for (int m1 = 0; m1 < sz; m1++) {
      for (int m2 = 0; m2 < sz; m2++) {
        ways[0] = 0, ways[1] = 1;
        for (int bit = 0; bit < l; bit++) {
          int zid1 = !!(m1 & (1 << bit));
          int zid2 = !!(m2 & (1 << bit));
          nways[0] = add(ways[0], ways[1]);
          nways[1] = add(ways[0], ways[1]);
          if (zid1 && zid2) {
            nways[1] = ways[0];
          }
          ways[0] = nways[0];
          ways[1] = nways[1];
        }
        coefs[m1][m2] = ways[1];
      }
    }
    cin >> cnt[l];
    for (int mask = 0; mask < (1 << (l - 1)); mask++) {
      dp[mask + (1 << (l - 1))] = dp[mask];
      dp[mask] = 0;
    }

    modMatrix cur(1, sz, M), mlt(sz, sz, M);
    for (int i = 0; i < sz; i++) {
      cur.a[0][i] = dp[i];
      for (int j = 0; j < sz; j++) {
        mlt.a[i][j] = coefs[i][j];
      }
    }

    cur = cur * (mlt ^ cnt[l]);
    for (int i = 0; i < sz; i++) {
      dp[i] = cur.a[0][i];
    }


  }
  cout << dp[(1 << 7) - 1] << "\n";

  return 0;
}