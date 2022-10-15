#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n, k, a[N], aok[N];

bool ok(int bound) {
  int j = 1;
  for (int i = 1; i <= n; i++) {
    while (a[i] - a[j] > bound) {
      j++;
    }
    bool ok = (i >= k && aok[i - k] >= j - 1);
    if (ok) {
      aok[i] = i;
    } else {
      aok[i] = aok[i - 1];
    }
  }
  return (aok[n] == n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int l = 0, r = (int) 1e9, ans;
  while (l <= r) {
    int m = (l + r) / 2;
    if (ok(m)) {
      ans = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  cout << ans << "\n";
}