#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const int M = (int) 1e9 + 7;
int fact[N];
int ifact[N];

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

int comb(int n, int k) {
  assert(0 <= n && n < N);
  assert(0 <= k && k <= n);
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

unordered_map<ll, int> dt;

int get(int n, int s) {
  if (n > s) return 0;
  ll h = (ll) s * (ll) N + n;
  if (dt.count(h)) return dt[h];
  vector<int> d;
  for (int i = 1; i * i <= s; i++) {
    if (s % i == 0) {
      d.push_back(i);
      if (i != s / i) {
        d.push_back(s / i);
      }
    }
  }
  int sol = comb(s - 1, n - 1);

  for (auto &x : d) {
    if (x > 1) {
      sol = add(sol, -get(n, s / x));
    }
  }
  dt[h] = sol;
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  int t;
  cin >> t;
  while (t--) {
    int s, n;
    cin >> s >> n;
    cout << get(n, s) << "\n";
  }
}