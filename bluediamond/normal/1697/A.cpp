#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE


  int Tests;
  cin >> Tests;

  for (int testCase = 1; testCase <= Tests; testCase++) {
    int n, m, Sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      Sum += x;
    }
    cout << max(0, Sum - m) << "\n";
  }
}