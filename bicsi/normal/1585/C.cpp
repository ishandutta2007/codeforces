#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> neg, pos;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      if (x < 0) neg.push_back(-x);
      else pos.push_back(x);
    }
    int sub = 0; long long add = 0;
    for (auto v : {pos, neg}) {
      sort(v.rbegin(), v.rend());
      if (v.empty()) continue;
      sub = max(sub, v[0]);
      for (int i = 0; i < (int)v.size(); i += k)
        add += 2 * v[i];
    }
    cout << add - sub << '\n';
  }

  return 0;
}