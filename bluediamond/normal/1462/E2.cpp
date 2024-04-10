#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int n, m, k, a[N], fact[N], ifact[N];


int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  /**for (int i = 0; i <= 10; i++) {
    cout << i << " : " << fact[i] << " " << ifact[i] << " " << mul(fact[i], ifact[i]) << "\n";
  }
  return 0;**/
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    m--;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int j = 1, sol = 0;
    for (int i = 1; i <= n; i++) {
      while (j + 1 <= n && a[j + 1] - a[i] <= k) {
        j++;
      }
      int cnt = j - i;
      if (cnt >= m) {
        sol = add(sol, comb(cnt, m));
      }
    }
    cout << sol << "\n";
  }

}