#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int t;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> t;
  while (t--) {
    int n, bad = 0;
    cin >> n;
    vector<int> a(2, 0), b(2, 0);


    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      a[i % 2]++;
      b[x % 2]++;

      bad += (i % 2 != x % 2);
    }

    if (a == b) {
      cout << bad / 2 << "\n";
    } else {
      cout << "-1\n";
    }
  }

	return 0;
}