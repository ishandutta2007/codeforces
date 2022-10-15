#include <bits/stdc++.h>

using namespace std;

const int N = 300000 + 7;
int n, q, v[N], y, cnt[N], read[N], last, id[N], ret;

signed main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {
      v[++y] = x;
      id[y] = ++cnt[x];
      ret++;
    }
    if (t == 2) {
      ret -= cnt[x] - read[x];
      read[x] = cnt[x];
    }
    if (t == 3) {
      while (last < x) {
        last++;
        ret -= cnt[v[last]] - read[v[last]];
        read[v[last]] = max(read[v[last]], id[last]);
        ret += cnt[v[last]] - read[v[last]];
      }
    }
    cout << ret << "\n";
  }
  return 0;
}