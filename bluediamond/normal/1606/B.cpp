#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, sol = 0;
    cin >> n >> k;
    n--;

    int have = 1;
    while (have < k && n > 0) {
      n -= have;
      sol++;
      have *= 2;
    }


    if (n > 0) {
      sol += (n + k - 1) / k;
    }


    cout << sol << "\n";

  }
  return 0;
}