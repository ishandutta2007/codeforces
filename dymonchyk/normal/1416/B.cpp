#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    sum += v[i];
  }
  if (sum % n != 0) {
    cout << -1 << endl;
    return;
  }
  sum /= n;

  vector<pair<pair<int, int>, int>> ans;

  for (int i = 2; i <= n; ++i) {
    if (v[i] % i != 0) {
      int need = i - (v[i] % i);
      ans.push_back({{1, i}, need});
      v[1] -= need;
      v[i] += need;
    }

    int cnt = v[i] / i;
    if (cnt > 0) {
      ans.push_back({{i, 1}, cnt});
      v[i] -= cnt * i;
      v[1] += cnt * i;
    }
  }
  for (int i = 2; i <= n; ++i) {
    ans.push_back({{1, i}, sum});
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}