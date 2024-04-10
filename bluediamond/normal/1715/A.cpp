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

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1) {
      cout << "0\n";
      continue;
    }
    int cost = 2 * ((n - 1) + (m - 1));
    cout << cost - max(n, m) + 2 << "\n";
  }
  return 0;
}
/**
**/