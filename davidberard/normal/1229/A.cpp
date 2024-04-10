#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 7070;
ll a[N], b[N];
bool good[N];
bool take[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  bool fg = 0;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    for (int j=1; j<i; ++j) {
      if (a[j] == a[i]) {
        fg = 1;
        good[i] = 1;
      }
    }
  }
  for (int i=1; i<=n; ++i) {
    cin >> b[i];
  }
  if (!fg) {
    cout << 0 << endl;
    return 0;
  }
  for (int i=1; i<=n; ++i) {
    if (!good[i]) continue;
    for (int j=1; j<=n; ++j) {
      if ((a[j]|a[i]) == a[i]) {
        take[j] = 1;
      }
    }
  }
  ll ans = 0;
  for (int i=1; i<=n; ++i) {
    if (take[i]) {
      //cerr << "I " << i << " " << b[i] << endl;
      ans += b[i];
    }
  }
  cout << ans << "\n";
  return 0;
}