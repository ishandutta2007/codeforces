#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, q, a[N], take[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int tst;
  cin >> tst;
  for (int tc = 1; tc <= tst; tc++) {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      take[i] = 0;
    }
    reverse(a + 1, a + n + 1);
    int c = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= c) {
        take[i] = 1;
        continue;
      }
      if (c + 1 <= q) {
        take[i] = 1;
        c++;
        continue;
      }
    }
    reverse(take + 1, take + n + 1);
    for (int i = 1; i <= n; i++) {
      cout << take[i];
    }
    cout << "\n";
  }
}