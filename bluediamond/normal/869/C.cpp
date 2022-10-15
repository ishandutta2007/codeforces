#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5000 + 7;
const int M = 998244353;
int a, b, c, fact[N], ifact[N];

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {return a * (ll) b % M;}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a); b /= 2;
  }
  return r;
}

int dv(int a, int b) {return mul(a, pw(b, M - 2));}

int comb(int n, int k) {return mul(fact[n], mul(ifact[k], ifact[n - k]));}

int f(int a, int b) {
  int ret = 0;
  for (int k = 0; k <= min(a, b); k++) ret = add(ret, mul(fact[k], mul(comb(a, k), comb(b, k))));
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1; for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]); for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  cin >> a >> b >> c;
  int ret = 1;
  ret = mul(ret, f(a, b));
  ret = mul(ret, f(a, c));
  ret = mul(ret, f(b, c));
  cout << ret << "\n";
}