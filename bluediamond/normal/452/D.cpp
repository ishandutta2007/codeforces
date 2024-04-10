#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int k, n1, n2, n3, t1, t2, t3;
vector<int> la;

int get(int l, int r) {
  assert(l <= r && r < (int) la.size());
  if (l <= 0) return la[r];
  return la[r] - la[l - 1];
}

signed main() {
  ///freopen ("input", "r", stdin);
  cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
  la.push_back(min({n1, n2, n3}));
  while (la.back() < k) {
    la.push_back(la.back());
    while (1) {
      la.back()++;
      bool ok = 1;
      ok &= (get((int) la.size() - t1, (int) la.size() - 1) <= n1);
      ok &= (get((int) la.size() - t2, (int) la.size() - 1) <= n2);
      ok &= (get((int) la.size() - t3, (int) la.size() - 1) <= n3);
      if (!ok) {
        la.back()--;
        break;
      }
    }
  }
  cout << (int) la.size() + t1 + t2 + t3 - 1 << "\n";
  return 0;
}
/**



**/