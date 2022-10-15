#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int n, a[N];


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int tot = 0;
    set<int> nums;
    for (int i = 1; i <= n; i++) nums.insert(a[i]);
    for (int i = 1; i <= n; i++) {
      if (n > 300) break;
      for (int j = 1; j < i; j++) {
        int dif = abs(a[i] - a[j]);
        if (!nums.count(dif)) {
          nums.insert(dif);
          a[++n] = dif;
          tot++;
          if (n > 300) break;
        }
      }
    }

    bool good = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++) {
        if (a[i] == a[j]) good = 0;
      }
    }
    if (n > 300 || !good) {
      cout << "NO\n";
      continue;
    }
    cout << "yes\n";
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}