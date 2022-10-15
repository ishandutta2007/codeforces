#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 998244353;

int rep(int x) {
  x %= M;
  if (x < 0) x += M;
  return x;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = rep(r * a);
    a = rep(a * a);
    b /= 2;
  }
  return r;
}

const int N = (int) 1e6 + 7;
int n, divis[N], all;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  all = 1;
  for (int j = 1; j < n; j++) {
    for (int i = 2 * j; i <= n; i += j) {
      divis[i]++;
    }
    all = rep(2 * all + divis[j]);
  }
  cout << all + divis[n] << "\n";
  return 0;
}