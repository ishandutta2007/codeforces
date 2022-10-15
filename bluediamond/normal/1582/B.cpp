#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 0;
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
    int n, z = 0, o = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      z += (x == 0);
      o += (x == 1);
    }
    int sol = o;
    for (int i = 1; i <= z; i++) {
      sol *= 2;
    }
    cout << sol << "\n";

  }

  return 0;
}
/**



**/