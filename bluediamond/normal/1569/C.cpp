#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M =  998244353;

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

const int N = (int) 2e5 + 7;
int fact[N], ifact[N];

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


  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    if (a[n - 2] == a[n - 1]) {
      cout << fact[n] << "\n";
      continue;
    }
    if (a[n - 2] + 1 != a[n - 1]) {
      cout << "0\n";
      continue;
    }
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      cnt += (a[j] == a[n - 2]);
    }
    int total = fact[n], bad = 0;
    int ways = comb(n, cnt + 1);
    bad = mul(ways, fact[cnt]);
    bad = mul(bad, fact[n - cnt - 1]);
    cout << add(total, -bad) << "\n";
  }
}