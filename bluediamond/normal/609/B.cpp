#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, m, f[10];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    x--;
    f[x]++;
  }

  ll ans = n * (ll) (n - 1) / 2;
  for (int i = 0; i < m; i++) {
    ans -= f[i] * (ll) (f[i] - 1) / 2;
  }
  cout << ans << "\n";

  return 0;
}