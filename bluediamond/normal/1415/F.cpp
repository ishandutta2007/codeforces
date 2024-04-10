#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5000 + 7;
const ll INF = (ll)1e18 + 7;
int n;
ll x[N];
ll t[N];
ll mint[N];
bool ok[N][N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  x[0] = t[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i];
  }
  for (int i = 0; i <= n; i++) {
    mint[i] = INF;
  }
  mint[0] = 0;
  for (int i = 0; i <= n; i++) {
    if (mint[i] <= t[i]) {
      mint[i + 1] = min(mint[i + 1], max(mint[i] + abs(x[i + 1] - x[i]), t[i]));
      for (int j = i + 2; j <= n; j++) {
        if (max(mint[i] + abs(x[j] - x[i]), t[i]) + abs(x[j] - x[i + 1]) <= t[i + 1]) {
          ok[i + 1][j] = 1;
        }
      }
    }
    if (ok[i][i + 1] && i + 2 <= n) {
      mint[i + 2] = min(mint[i + 2], max(t[i] + abs(x[i + 2] - x[i]), t[i + 1]));
      for (int j = i + 3; j <= n; j++) {
        if (max(t[i] + abs(x[j] - x[i]), t[i + 1]) + abs(x[j] - x[i + 2]) <= t[i + 2]) {
          ok[i + 2][j] = 1;
        }
      }
    }
    for (int j = i + 2; j <= n; j++) {
      if (ok[i][j] && t[i] + abs(x[i + 1] - x[i]) <= t[i + 1]) {
        ok[i + 1][j] = 1;
      }
    }
  }
  if (mint[n] <= t[n] || ok[n - 1][n]) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}