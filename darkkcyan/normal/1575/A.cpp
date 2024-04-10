#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end(), [&](auto a, auto b) {
    for (int i = 0; i < m; i++) {
      if (a.first[i] != b.first[i]) {
        if (i % 2 == 0) {
          return a.first[i] < b.first[i];
        } else {
          return a.first[i] > b.first[i];
        }
      }
    }
  });
  for (auto e : v) {
    cout << e.second << " ";
  }
  return 0;
}