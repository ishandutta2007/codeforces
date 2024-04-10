#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> arr[300005];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; ++i) {
    arr[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    arr[x].push_back(i);
  }

  vector<pair<int, int>> v;
  for (int i = 1; i <= n; ++i) {
    int prev = -1, mn = 0;
    for (int x : arr[i]) {
      mn = max(mn, x - prev);
      prev = x;
    }
    mn = max(mn, n - prev);
    v.push_back({mn, i});
  }
  sort(v.begin(), v.end());
  int ptr = 0, cur = n + 1;
  for (int i = 1; i <= n; ++i) {
    while (ptr < v.size() && v[ptr].first <= i) cur = min(cur, v[ptr].second), ++ptr;
    cout << (cur == n + 1 ? -1 : cur) << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t)
    solve();
  return 0;
}