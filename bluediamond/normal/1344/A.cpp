#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += i;
      a[i] %= n;
      if (a[i] < 0) {
        a[i] += n;
      }
    }
    sort(a.begin(), a.end());
    bool yes = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) {
        yes = 0;
        break;
      }
    }
    if (yes) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}