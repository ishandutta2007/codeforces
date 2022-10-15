#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b, c;
  cin >> a >> b >> c;

  ll res = 2 * c + 2 * min(a, b) + (a != b);
  cout << res << "\n";

  return 0;
}