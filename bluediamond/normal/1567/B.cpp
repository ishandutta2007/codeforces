#include <bits/stdc++.h>

using namespace std;

const int N = (int) 3e5 + 7;
int n, pref[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  for (int i = 1; i < N; i++) {
    pref[i] = pref[i - 1] ^ i;
  }

  int t;
  cin >> t;
  while (t--) {
    int MEX, XOR, before, sol = 0;
    cin >> MEX >> XOR;
    before = pref[MEX - 1];
    XOR ^= before;
    sol += MEX;
    if (XOR) {
      if (XOR == MEX) {
        sol += 2;
      } else {
        sol += 1;
      }
    }
    cout << sol << "\n";
  }

}