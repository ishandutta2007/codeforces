#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n;
    cin >> n;
    if (n % 2 == 1) {
      cout << "0\n";
    } else {
      int sol = 1;
      for (int i = 1; i <= n / 2; i++) {
        sol = (ll) sol * i * i % 998244353;
      }
      cout << sol << "\n";
    }
  }


  return 0;
}