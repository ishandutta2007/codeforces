#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<string> a(n), b(m);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  int t; cin >> t;
  while (t--) {
    int y; cin >> y; --y;
    cout << a[y % n] << b[y % m] << '\n';
  }

  return 0;
}