#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;

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

const int N = 5000 + 7;
const int I2 = dv(1, 2);
int n, a[N], up[N][2 * N], ret[N]; /// I know down is just [N][N], but whatever
int pre[N], ip[N];

int down(int i, int j) {
  if (i + j > n) return 0;
  return mul(pre[i + j], ip[i]);
}

signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  pre[1] = 1;
  for (int i = 2; i <= n; i++) {
    pre[i] = mul(pre[i - 1], a[i - 1]);
  }
  for (int i = 0; i <= n; i++) {
    ip[i] = dv(1, pre[i]);
  }
  for (int i = 1; i <= n; i++) {
    up[i][0] = 1;
    for (int j = 1; j <= 2 * n - 2; j++) {
      up[i][j] = up[i - 1][j - 1];
    }
    if (i >= 2) {
      int pos = a[i - 1] - 1;
      for (int j = 2; j <= 2 * n - 2; j++) {
        up[i][j] = add(up[i][j], mul(pos, down(i, j - 2)));
      }
    }
  }

  for (int j = 1; j <= 2 * n - 2; j++) {
    for (int i = 1; i <= n; i++) {
      ret[j] = add(ret[j], mul(pre[i], up[i][j]));
      ret[j] = add(ret[j], mul(pre[i], down(i, j)));
    }
    cout << mul(ret[j], I2) << " ";
  }
  cout << "\n";
  return 0;
}