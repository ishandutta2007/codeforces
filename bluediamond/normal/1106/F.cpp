#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

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

const int K = 100 + 7;
const int M = 998244353;
int k, b[K], n, a;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
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

const int R = 33333;

int disc_log(int a, int b) {
  unordered_set<int> values;
  int inv_a = dv(1, a), cur = b, a_r = pw(a, R);
  for (int j = 0; j < R; j++) {
    values.insert(cur);
    cur = mul(cur, inv_a);
  }
  cur = 1;
  for (int x = 0; x < R; x++) {
    if (values.count(cur)) {
      int now = b;
      for (int j = 0; j < R; j++) {
        if (now == cur) {
          return x * R + j;
        }
        now = mul(now, inv_a);
      }
      assert(0);
    }
    cur = mul(cur, a_r);
  }
  cout << "-1\n";
  exit(0);
}


signed realMain() {
  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> b[i];
  }
  cin >> n >> a;
  {
    modMatrix init(1, k, M - 1);
    init.a[0][k - 1] = 1;
    modMatrix mult(k, k, M - 1);
    for (int j = 0; j + 1 < k; j++) {
      mult.a[j + 1][j] = 1;
    }
    for (int j = 0; j < k; j++) {
      mult.a[j][k - 1] = b[k - j];
    }
    mult = mult ^ (n - 1);
    init = init * mult;
    k = init.a[0][0];
  }
  cout << pw(3, disc_log(pw(3, k), a)) << "\n";
  return 0;
}