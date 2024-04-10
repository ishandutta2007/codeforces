#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

ll z;

bool chkCube(ll a) {
  ll L = 1, R = 1000000, x = 1;
  while (L <= R) {
    ll m = (L + R) / 2;
    if (m * m * m <= a)
      x = m, L = m + 1;
    else
      R = m - 1;
  }
  z = x;
  return (x * x * x) == a;
}

bool chkSube(ll a) {
  ll L = 1, R = 1000000000, x = 1;
  while (L <= R) {
    ll m = (L + R) / 2;
    if (m * m <= a)
      x = m, L = m + 1;
    else
      R = m - 1;
  }
  return (x * x) == a;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll j;
    cin >> j;
    ll b;
    cin >> b;
    if ((j * j % b == 0) && chkCube(j * j / b)) {
      if ((b % z == 0) && chkSube(b / z))
        cout << "Yes\n";
      else
        cout << "No\n";
    } else
      cout << "No\n";
  }
}