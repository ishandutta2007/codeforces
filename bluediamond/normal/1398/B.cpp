#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<pair<int, int>> a;
    for (auto &ch : s) {
      int x = ch - '0';
      if (a.empty() || x != a.back().first) {
        a.push_back({x, 0});
      }
      a.back().second++;
    }
    vector<int> b;
    for (auto &it : a) {
      if (it.first) {
        b.push_back(it.second);
      }
    }
    sort(b.rbegin(), b.rend());
    int sol = 0;
    for (int i = 0; i < (int) b.size(); i += 2) {
      sol += b[i];
    }
    cout << sol << "\n";
  }
  return 0;
}
/**
**/