#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
typedef long double ld;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}


signed realMain() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s.insert(x);
  }
  cout << (int) s.size() - s.count(0) << "\n";
  return 0;
}