#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 2e5 + 7;
int n;
int a[N];
int s[N];
int val[N];
bool good[N];

bool ok() {
  s[1] = a[1];
  good[0] = good[1] = 1;
  for (int i = 2; i <= n; i++) {
    s[i] = s[i - 2] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    val[i] = s[i] - s[i - 1];
  }
  for (int i = n; i >= 1; i--) {
    if (i + 2 <= n) {
      val[i] = min(val[i], val[i + 2]);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (!(s[i - 1] <= s[i])) {
      return 0;
    }
    good[i] = 1;
  }
  return (s[n - 1] == s[n]);
}

bool solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    good[i] = 0;
  }
  if (ok()) {
    return 1;
  }
  int total[2], add[2];
  total[0] = total[1] = 0;
  for (int i = 1; i <= n; i++) {
    total[i % 2] += a[i];
  }
  for (int i = 1; i < n; i++) {
    int x = a[i];
    int y = a[i + 1];
    if (total[i % 2] - x + y == total[1 - i % 2] - y + x) {
      if (!good[i - 1]) continue;
      add[i % 2] = y - x;
      add[1 - i % 2] = x - y;
      if (s[i - 1] > s[i] + add[i % 2]) {
        continue;
      }
      bool bad = 0;
      for (int j = i + 1; j <= min(i + 3, n); j++) {
        if (add[(j - 1) % 2] - add[j % 2] > val[j]) {
          bad = 1;
          break;
        }
      }
      if (!bad) {
        return 1;
      }
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 //// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    if (solve()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}