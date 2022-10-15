#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, a[N], b[N], sum;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);

  int x = sum / n, y = x + 1;
  int cx, cy;

  if (sum % n == 0) {
    cx = n;
    cy = 0;
  } else {
    cy = sum % n;
    cx = n - cy;
  }

  for (int i = 1; i <= n; i++) {
    if (i <= cx) {
      b[i] = x;
    } else {
      b[i] = y;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += abs(a[i] - b[i]);
  }
  cout << ans / 2 << "\n";

  return 0;
}