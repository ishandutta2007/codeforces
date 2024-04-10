#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;
#define int ll


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE


  if (home) {
    freopen ("input", "r", stdin);
  }

  int t;
  cin >> t;
  while (t--) {
    int c1, c2, c3, sum, one = 0;
    cin >> c1 >> c2 >> c3;
    sum = c1 + 2 * c2 + 3 * c3;
    sum /= 2;
    int t = min(sum / 3, c3);
    sum -= 3 * t;
    one += 3 * t;
    t = min(sum / 2, c2);
    sum -= 2 * t;
    one += 2 * t;
    t = min(sum, c1);
    sum -= t;
    one += t;
    int other = c1 + 2 * c2 + 3 * c3 - one;
    assert(one <= other);
    cout << other - one << "\n";

  }

  return 0;
}
/**



**/