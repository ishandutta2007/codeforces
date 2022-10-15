#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, k;
int a[N];

int adun(int a, int b) {
  ll x = a, y = b;
  ll sum = x + y;
  return min(sum, (ll) 2e9);
}

bool ok(int x) {
  int i = 0;
  while (i + 1 <= n && a[i + 1] < x) {
    i++;
  }
  int cnt = n - i;
  int need = (n + 1) / 2 - cnt;
  if (need <= 0) {
    return 1;
  }
  int sum = 0;
  for (int j = i; j >= i - need + 1; j--) {
    sum = adun(sum, x - a[j]);
    if (sum > k) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int l = 0, r = (int) 2e9, ans = 0;

  while (l <= r) {
    int m = l + (r - l) / 2;
    if (ok(m)) {
      ans = m;
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << ans << "\n";

  return 0;
}