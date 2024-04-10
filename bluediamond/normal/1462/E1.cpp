#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long
const int N = (int) 2e5 + 7;
int n, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int j = 1, sol = 0;
    for (int i = 1; i <= n; i++) {
      while (j + 1 <= n && a[j + 1] - a[i] <= 2) {
        j++;
      }
      int cnt = j - i;
      if (cnt >= 2) {
        sol += cnt * (cnt - 1) / 2;
      }
    }
    cout << sol << "\n";
  }

}