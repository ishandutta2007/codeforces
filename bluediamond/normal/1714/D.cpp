#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string t;
    int n;
    cin >> t >> n;
    int m = t.size();
    vector<tuple<int, int, int>> r(m);
    for (int j = 1; j <= n; j++) {
      string s;
      cin >> s;
      int k = s.size();
      for (int i = 0; i <= m-k; i++) {
        if (t.substr(i, k) == s) {
          r[i] = max(r[i], make_tuple(i+k, j, i+1));
        }
      }
    }
    for (int i = 1; i < m; i++) {
      r[i] = max(r[i], r[i-1]);
    }
    vector<pair<int, int>> ans;
    int cur = 0;
    while (cur < m) {
      if (get<0>(r[cur]) <= cur) {
        ans.clear();
        break;
      }
      ans.emplace_back(get<1>(r[cur]), get<2>(r[cur]));
      cur = get<0>(r[cur]);
    }
    if (ans.empty()) {
      cout << "-1\n";
      continue;
    }
    cout << ans.size() << '\n';
    for (pair<int, int>& p: ans) {
      cout << p.first << " " << p.second << '\n';
    }
  }
}