#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

map<pair<int, int>, pair<char, char>> mp;

set<pair<int, int>> same, diff;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    string type;
    cin >> type;
    if (type == "+") {
      int u, v;
      char c;
      cin >> u >> v >> c;
      pair<int, int> pr = {min(u, v), max(u, v)};
      if (u < v) {
        if (!mp.count(pr)) {
          mp[pr] = {0, 0};
        }
        mp[pr].first = c;
      } else {
        if (!mp.count(pr)) {
          mp[pr] = {0, 0};
        }
        mp[pr].second = c;
      }
      if (mp[pr].first && mp[pr].second) {
        if (mp[pr].first == mp[pr].second) {
          same.insert(pr);
        }
        diff.insert(pr);
      }
    } else if (type == "-") {
      int u, v;
      cin >> u >> v;
      pair<int, int> pr = {min(u, v), max(u, v)};
      if (mp[pr].first && mp[pr].second) {
        if (mp[pr].first == mp[pr].second) {
          same.erase(pr);
        }
        diff.erase(pr);
      }

      if (u < v) {
        mp[pr].first = 0;
      } else {
        mp[pr].second = 0;
      }
    } else if (type == "?") {
      int k;
      cin >> k;
      if (k%2) {
        cout << (diff.empty() ? "NO" : "YES") << "\n";
      } else {
        cout << (same.empty() ? "NO" : "YES") << "\n";
      }
    }
  }
  return 0;
}