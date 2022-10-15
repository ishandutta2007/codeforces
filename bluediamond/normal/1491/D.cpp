#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(int a, int b) {
  if (a > b) return 0;
  /// we use hall's theorem to prove that there's a matching
  int in_a = 0, in_b = 0;
  for (int k = 0; k < 30; k++) {
    in_a += !!(a & (1 << k));
    in_b += !!(b & (1 << k));
    if (in_a < in_b) return 0;
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (solve(a, b) ? "YES" : "NO") << "\n";
  }
}