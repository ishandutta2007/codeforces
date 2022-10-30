#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> disp;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      disp.push_back(a[i]);
    }
    sort(disp.begin(), disp.end());
    disp.erase(unique(disp.begin(), disp.end()), disp.end());
    vector<vector<int>> p(n + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = lower_bound(disp.begin(), disp.end(), a[i]) - disp.begin() + 1;
      p[a[i]].push_back(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      if ((int)p[i].size() <= 1) {
        continue;
      }
      ll sum = 0;
      for (auto pos: p[i]) {
        ans += sum * (n - pos + 1);
        sum += pos;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}