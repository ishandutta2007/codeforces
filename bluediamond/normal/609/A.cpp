#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 7;
int n, m, a[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    m -= a[i];
    if (m <= 0) {
      cout << i << "\n";
      return 0;
    }
  }

  return 0;
}