#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;

int realMain();


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

const int N = (int) 2e5 + 7;
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

int sum, fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int s(int n, int k) {
  if (n < k) return 0;
  /// the number of ways to divide n elements into k unordered sets = k! * the number of ways to divide n elements into k sets
  /// the number of ways to divide n elements into k sets = ret
  int ret = 0;
  for (int zero = 0; zero <= k; zero++) {
    int cur = comb(k, zero);
    cur = mul(cur, pw(k - zero, n));
    if (zero % 2 == 0) {
      ret = add(ret, +cur);
    } else {
      ret = add(ret, -cur);
    }
  }
  ret = mul(ret, ifact[k]);
  return ret;
}

signed realMain() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int w;
    cin >> w;
    sum = add(sum, w);
  }
  int cnt = s(n, k);
  cnt = add(cnt, mul(n - 1, s(n - 1, k)));
  cout << mul(sum, cnt) << "\n";
}