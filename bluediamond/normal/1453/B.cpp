#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll sum = 0, sol;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i + 1 < n; i++) {
      sum += abs(a[i + 1] - a[i]);
    }
    sol = sum;
    sol = min(sol, sum - abs(a[1] - a[0]));
    sol = min(sol, sum - abs(a[n - 1] - a[n - 2]));
    for (int i = 0; i + 2 < n; i++) {
      sol = min(sol, sum - abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i + 2]) + abs(a[i] - a[i + 2]));
    }
    cout << sol << "\n";

  }
}