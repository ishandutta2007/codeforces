#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int r, n;
  cin >> r >> n;
  if (n == 0) {
    cout << ((r & 1) ? "WIN\n" : "LOSE\n");
    return 0;
  }
  vector<pair<int, int>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  int sol = (p[0].first - 1) ^ (r - p.back().first);
  for (int i = 1; i < (int) p.size(); i++) {
    sol ^= ((p[i].first - p[i - 1].first - (p[i - 1].second == p[i].second)) % 2);
  }
  cout << ((sol) ? "WIN\n" : "LOSE\n");
}