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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    sort(a.begin(), a.end());
    if (a.back() <= d || a[0] + a[1] <= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}