#include "bits/stdc++.h"

using namespace std;

int n;

void solve() {
  cin >> n;
  vector<int> cur = {};

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    if (x == 1)
      cur.push_back(0);

    while (x != cur.back() + 1)
      cur.pop_back();

    cur.back()++;
    for (int i = 0; i < (int) cur.size(); ++i) {
      cout << cur[i] << (i + 1 == cur.size() ? "\n" : ".");
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}