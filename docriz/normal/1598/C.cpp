#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum * 2 % n) {
      cout << "0\n";
      continue;
    }
    ll need = sum * 2 / n;
    map<ll, int> have;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += have[need - a[i]];
      have[a[i]] += 1;
    }
    cout << ans << "\n";
  }
  return 0;
}