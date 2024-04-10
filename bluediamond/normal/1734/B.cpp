#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ///freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        cout << (j == 1 || j == i) << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}