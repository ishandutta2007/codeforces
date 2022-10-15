#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  const int inf = (int) 1e9 + 7;

  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), distinctElems, seen(n, 0), maxCover(n, -1);
    vector<vector<int>> location(n);

    for (auto &x : a) {
      cin >> x;
      distinctElems.push_back(x);
    }
    sort(distinctElems.begin(), distinctElems.end());
    distinctElems.resize(unique(distinctElems.begin(), distinctElems.end()) - distinctElems.begin());
    for (int i = 0; i < n; i++) {
      a[i] = lower_bound(distinctElems.begin(), distinctElems.end(), a[i]) - distinctElems.begin();
      location[a[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      l--;
      maxCover[l] = max(maxCover[l], r);
    }
    for (int i = 1; i < n; i++) {
      maxCover[i] = max(maxCover[i - 1], maxCover[i]);
    }

    int sol = inf, R = -1, stop = n;
    vector<int> maximize(n, -1);

    for (int i = 0; i < n; i++) {
      int x = a[i];
      int location_i = lower_bound(location[x].begin(), location[x].end(), i) - location[x].begin();
      int location_next = lower_bound(location[x].begin(), location[x].end(), maxCover[i]) - location[x].begin() - 1;

      if (location_i < location_next) {
        stop = min(stop, location[x][location_i + 1]);
        R = max(R, location[x][location_next - 1]);
        maximize[i] = location[x][location_next];
      }
    }

    if (R == -1) {
      cout << "0\n";
      continue;
    }

    assert(stop < n);
    for (int L = 0; L <= stop; L++) {

      sol = min(sol, R - L + 1);
      R = max(R, maximize[L]);
    }
    cout << sol << "\n";
  }


  return 0;
}