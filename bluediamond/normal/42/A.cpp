#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  double x, ans, sy = 0;
  cin >> n >> x;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sy += a[i];
  }
  for (int i = 0; i < n; i++) {
    double y;
    cin >> y;
    if (i == 0) {
      ans = y / a[i];
    } else {
      ans = min(ans, y / a[i]);
    }
  }
  ans *= sy;
  ans = min(ans, x);
  cout << fixed << setprecision(4) << ans << "\n";
}