#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> val(n, -1);

  n = k + 1;
  vector<pair<int, int>> ans;
  map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    cout << "? ";
    for (int j = 0; j < n; ++j) {
      if (j == i) continue;
      cout << j + 1 << " ";
    }
    cout << endl;

    int pos, val; cin >> pos >> val; --pos;
    ans.emplace_back(pos, val);
    cnt[val] += 1;
  }
  cout << "! " << k + 1 - cnt.begin()->second << endl;

  return 0;
}