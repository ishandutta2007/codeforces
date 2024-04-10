#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll c[100][100];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 100; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  int n, m, t;
  ll ans = 0;
  cin >> n >> m >> t;
  for (ll b = 4; b <= min(t, n); b++) {
    ll g = t - b;
    if (1 <= g && g <= m) {
      ans += c[n][b] * c[m][g];
    }
  }
  cout << ans << "\n";
}