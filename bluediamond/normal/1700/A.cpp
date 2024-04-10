#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n, m, sol = 0;
    cin >> n >> m;
    int r = 1, c = 1;
    while (r < n || c < m) {
      sol += (r - 1) * m + c;
      if (c < m) c++;
      else r++;
    }
    sol += (r - 1) * m + c;
    cout << sol << "\n";
  }
}