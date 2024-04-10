#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
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

signed realMain() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> f;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      f[x]++;
    }
    vector<int> a;
    for (auto &it : f) {
      a.push_back(it.second);
    }
    sort(a.begin(), a.end());
    set<pair<int, int>> s;
    int y = 0;
    for (auto &x : a) {
      s.insert({-x, y++});
    }
    while ((int) s.size() >= 2) {
      pair<int, int> ff = *s.begin(); s.erase(ff);
      pair<int, int> ss = *s.begin(); s.erase(ss);
      ff.first *= -1;
      ss.first *= -1;
      assert(ff.first >= 1);
      assert(ss.first >= 1);
      ff.first--;
      ss.first--;
      ff.first *= -1;
      ss.first *= -1;
      if (ff.first) s.insert(ff);
      if (ss.first) s.insert(ss);
    }
    int ret = 0;
    for (auto &it : s) {
      ret -= it.first;
    }
    cout << ret << "\n";
  }
  return 0;
}