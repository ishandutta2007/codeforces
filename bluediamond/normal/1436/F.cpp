#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 998244353;

int rep(int x) {
  x %= M;
  if (x < 0) {
    x += M;
  }
  return x;
}

int add(int a, int b) {
  a = rep(a);
  b = rep(b);
  return rep(a + b);
}

int mul(int a, int b) {
  a = rep(a);
  b = rep(b);
  return rep(a * b);
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

const int N = (int) 1e5 + 7;
int f[N];
int dp[N];

int get(int tot) {
  return mul(tot, pw(2, tot - 1));
}

int geta(int tot) {
  if (tot < 2) {
    return 0;
  }
  return add(pw(2, tot - 2), get(tot - 2));
}

int getb(int tot) {
  if (tot < 1) {
    return 0;
  }
  return get(tot - 1);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c;
  cin >> c;
  for (int i = 1; i <= c; i++) {
    int x, t;
    cin >> x >> t;
    f[x] = t;
  }
  for (int x = N - 1; x >= 1; x--) {
    int tot = 0;
    for (int y = x; y < N; y += x) {
      tot += f[y];
    }
    int a = geta(tot);
    int b = getb(tot);
    vector<pair<int, int>> v;
    for (int y = x; y < N; y += x) {
      if (f[y]) {
        v.push_back({y, f[y]});
      }
    }
    int pre = 0;
    for (int i = 0; i < (int) v.size(); i++) {
      int lol = pre;
      pre = add(pre, mul(v[i].second, v[i].first));
      lol = mul(lol, 2);
      lol = mul(lol, mul(v[i].first, v[i].second));
      lol = mul(lol, a);
      dp[x] = add(dp[x], lol);
      int ct = v[i].second;
      dp[x] = add(dp[x], mul(mul(ct, ct - 1), mul(a, mul(v[i].first, v[i].first))));
      dp[x] = add(dp[x], mul(ct, mul(b, mul(v[i].first, v[i].first))));
    }
    for (int y = 2 * x; y < N; y += x) {
      dp[x] = add(dp[x], -dp[y]);
    }
  }
  cout << dp[1] << "\n";
}