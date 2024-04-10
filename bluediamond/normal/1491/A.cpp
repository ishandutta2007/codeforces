#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, q, cnt = 0;
bitset<N> b;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x) {
      b[i] = 1;
      cnt++;
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      cin >> i;
      if (b[i]) {
        cnt--;
        b[i] = 0;
      } else {
        cnt++;
        b[i] = 1;
      }
    } else {
      int k;
      cin >> k;
      cout << (k <= cnt) << "\n";
    }
  }

}