#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 7;
int n, a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  ll x = 0, y = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= (n + 1) / 2) {
      x += a[i];
    } else {
      y += a[i];
    }
  }
  cout << x * x + y * y << "\n";
}