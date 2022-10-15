#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;
ll p[60];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  p[0] = 1;
  for (int i = 1; i < 60; i++) {
    p[i] = 2 * p[i - 1] % M;
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> f(60);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 0; j < 60; j++) {
        if (a[i] & (1LL << j)) {
          f[j]++;
        }
      }
    }
    ll ret = 0;
    for (int j = 0; j < n; j++) {
      ll sx = 0, sy = 0;
      for (int bit = 0; bit < 60; bit++) {
        if (a[j] & (1LL << bit)) {
          sx = (sx + p[bit] * f[bit]) % M;
          sy = (sy + p[bit] * n) % M;
        } else {
          sy = (sy + p[bit] * f[bit]) % M;
        }
      }
      ret = (ret + sx * sy) % M;
    }
    cout << ret << "\n";
  }
}