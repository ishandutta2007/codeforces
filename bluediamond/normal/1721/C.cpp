#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), nb(n, n - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = n - 2; i >= 0; i--) {
      if (b[i] < a[i + 1]) {
        nb[i] = i;
      } else {
        nb[i] = nb[i + 1];
      }
    }

    {
      int j = 0;
      for (int i = 0; i < n; i++) {
        while (b[j] < a[i]) {
          j++;
        }
        cout << b[j] - a[i] << " ";
      }
      cout << "\n";
    }
    {
      for (int i = 0; i < n; i++) {
        cout << b[nb[i]] - a[i] << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}