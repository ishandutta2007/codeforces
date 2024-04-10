#include <bits/stdc++.h>

using namespace std;

bool home = 1;
#define int ll
typedef long long ll;
///typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int K = 35;
int su[K], mn[K];
multiset<int> s, s2[K];

signed realMain() {
  int q;
  cin >> q;
  for (int j = 1; j <= q; j++) {
    string type;
    int x, p;
    cin >> type >> x;
    p = log2(x);
    if (type == "+") {
      s.insert(x);
      s2[p].insert(x);
      su[p] += x;
      mn[p] = *s2[p].begin();
    } else {
      s.erase(s.find(x));
      s2[p].erase(s2[p].find(x));
      su[p] -= x;
      if (su[p]) {
        mn[p] = *s2[p].begin();
      }
    }
    int ret = 0, sum = 0;
    for (int k = 0; k < K; k++) {
      ret += (su[k] && mn[k] > 2 * sum);
      sum += su[k];
    }
    cout << (int) s.size() - ret << "\n";
  }
  return 0;
}