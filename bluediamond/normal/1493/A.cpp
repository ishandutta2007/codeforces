#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
      if (i == k) continue;
      if (2 * i >= k) ret.push_back(i);
    }
    cout << (int) ret.size() << "\n";
    for (auto &x : ret) cout << x << " ";
    cout << "\n";
  }
}