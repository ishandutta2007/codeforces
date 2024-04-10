#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;

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

const int N = (int) 1e6 + 7;
int n, ret, fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  cin >> n;
  if (n == 1) {
    cout << "3\n";
    return 0;
  }
  for (int c1 = 1; c1 <= n; c1++) {
    int val = add(0, -pw(3, n - c1));
    int sum = 0;
    sum = add(sum, pw(add(val, 1), n));
    int ways = pw(val, n);
    sum = add(sum, -ways);
    sum = add(0, -sum);
    sum = mul(sum, comb(n, c1));
    if ((n + c1) & 1) {
      ret = add(ret, -sum);
    } else {
      ret = add(ret, +sum);
    }
  }
  ret = mul(ret, 3);
  for (int c = 1; c <= n; c++) {
    int sgn;
    if (c & 1) {
      sgn = +1;
    } else {
      sgn = -1;
    }
    int ways = comb(n, c);
    ways = mul(ways, pw(3, ((ll) c + (ll) n * (n - c)) % (M - 1)));
    ret = add(ret, sgn * add(ways, ways));
  }
  cout << ret << "\n";
}