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
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

const int N = 12345 + 7;
int fact[N], ifact[N];

int comb(int n, int k) {
  if (0 <= k && k <= n) return mul(fact[n], mul(ifact[k], ifact[n - k]));
  return 0;
}

int cnt(int sum, int k) {
  if (k == 0) return (sum == 0);
  return comb(sum + k - 1, k - 1);
}

int f(int p, int s, int mx) {
  if (s < 0 || p * mx < s) return 0;
  int ret = 0;
  for (int wrong = 0; wrong <= p; wrong++) {
    int coef = (wrong % 2 == 0) ? +1 : -1;
    int now = 1;
    now = mul(now, comb(p, wrong));
    now = mul(now, cnt(s - (mx + 1) * wrong, p));
    ret = add(ret, coef * now);
  }
  return ret;
}

int main() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  int p, s, r, ret = 0;
  cin >> p >> s >> r;
  for (int score = r; score <= s; score++) {
    int init = ret;
    for (int cnt = 1; cnt <= p; cnt++) {
      int now = 1;
      now = mul(now, dv(1, cnt));
      now = mul(now, comb(p - 1, cnt - 1));
      now = mul(now, f(p - cnt, s - cnt * score, score - 1));
      ret = add(ret, now);
    }
  }
  ret = dv(ret, cnt(s - r, p));
  cout << ret << "\n";
}