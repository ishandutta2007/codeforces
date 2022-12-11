#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, a[4];
  cin >> n >> k;
  for (int i = 0; i < 4; ++i) cin >> a[i];
  if (n == 4 or n + 1 > k) {
    cout << -1 << endl;
    return 0;
  }
  cout << a[0] << ' ' << a[2];
  for (int i = 1; i <= n; ++i) {
    bool tt = true;
    for (int j = 0; j < 4; ++j) {
      if (i == a[j]) tt = false;
    }
    if (tt) cout << ' ' << i;
  }
  cout << ' ' << a[3] << ' ' << a[1] << endl;
  cout << a[2] << ' ' << a[0];
  for (int i = 1; i <= n; ++i) {
    bool tt = true;
    for (int j = 0; j < 4; ++j) {
      if (i == a[j]) tt = false;
    }
    if (tt) cout << ' ' << i;
  }
  cout << ' ' << a[1] << ' ' << a[3] << endl;
}