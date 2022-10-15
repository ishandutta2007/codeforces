#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
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

int fact(int n) {
  int sol = 1;
  for (int i = 1; i <= n; i++) {
    sol = mul(sol, i);
  }
  return sol;
}

int comb(int n, int k) {
  if (k < 0 || k > n) return 0;
  return dv(fact(n), mul(fact(k), fact(n - k)));
}


const int N = 200000 + 7;
int ord[N], inv[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k, cnt = 0;
  cin >> n >> k;

  for (int i = 0; i < n; i++) cin >> ord[i];
  for (int i = 0; i < n; i++) inv[ord[i]] = i;
  inv[n] = -1;
  for (int i = 0; i + 1 < n; i++) cnt += (inv[ord[i] + 1] > inv[ord[i + 1] + 1]);


  cout << comb(k - cnt + n - 1, n) << "\n";

  return 0;
}