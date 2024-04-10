#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> evs;
  for (int i = 0; i < n; ++i) {
    int k; cin >> k;
    
    vector<int> v(k);
    for (int i = 0; i < k; ++i) {
      cin >> v[i]; 
    }

    bool desc = true;
    for (int i = 1; i < k; ++i) {
      if (v[i - 1] < v[i])
        desc = false;
    }

    if (desc) {
      evs.emplace_back(v.back(), 1);
      evs.emplace_back(v.front(), 0);
    }
  }

  sort(evs.begin(), evs.end());
  long long ans = 1LL * n * n;
  int now = 0;
  for (auto p : evs) {
    if (p.second == 1) ans -= now;
    else now += 1;
  }
  cout << ans << endl;

  return 0;
}