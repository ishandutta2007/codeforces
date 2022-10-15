#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

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

bool prie(int x) {
  if (x <= 1) return 0;
  for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
  return 1;
}

const int N = 70 + 7;
vector<int> prm;
int n, c[N], fact[N], ifact[N], dp[1 << 20], dp2[1 << 20], mask[N];

int comb(int n, int k) {return mul(fact[n], mul(ifact[k], ifact[n - k]));}

int nr(int x) {
  int sol = 1;
  for (int i = 2; i * i <= x; i++) {
    int cnt = 0;
    while (x % i == 0) {
      cnt++;
      x /= i;
    }
    if (cnt % 2 == 1) sol *= i;
  }
  sol *= x;
  return sol;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1; for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]); for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);
  for (int i = 1; i <= 70; i++) if (prie(i)) prm.push_back(i);

  for (int i = 1; i <= 70; i++) {
    for (int it = 0; it < (int) prm.size(); it++) if (i % prm[it] == 0) mask[i] += (1 << it);
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    c[nr(x)]++;
  }
  dp[0] = 1;
  for (int x = 1; x <= 70; x++) {
    if (c[x] == 0) continue;
    int par = pw(2, c[x] - 1);
    int impar = pw(2, c[x] - 1);
    for (int i = 0; i < (1 << 20); i++) {
      dp2[i] = add(dp2[i], mul(dp[i], par));
      dp2[i ^ mask[x]] = add(dp2[i ^ mask[x]], mul(dp[i], impar));
    }
    for (int i = 0; i < (1 << 20); i++) {
      dp[i] = dp2[i];
      dp2[i] = 0;
    }
  }
  cout << add(dp[0], -1) << "\n";
}