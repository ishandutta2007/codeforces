#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  ll x, g = 0;
  cin >> x;
  for (int i = 2; i <= n; i++) {
    ll y;
    cin >> y;
    g = __gcd(abs(y - x), g);
  }
  for (int i = 1; i <= m; i++) {
    ll y;
    cin >> y;
    cout << __gcd(x + y, g) << " ";
  }
  cout << "\n";
}