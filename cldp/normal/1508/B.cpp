#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

vector<LL> Solve(LL n, LL k) {
  vector<LL> ans;
  set<LL> s;
  for (LL j = 0; j < n; ++j) s.insert(j);
  for (LL i = 0; i < n; ++i) {
    auto iter = s.begin();
    for (LL j = n - 2 - i; j >= 0; --j) {
      if (((1LL << j) & k) == 0) break;
      ++iter;
    }
    ans.push_back(*iter);
    s.erase(iter);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    LL n, k;
    cin >> n >> k;
    --k;
    vector<LL> ans;
    if (n <= 61 && k > (1LL << (n - 1)) - 1) {
      cout << -1 << '\n';
      continue;
    }
    LL i;
    for (i = 0; i + 61 < n; ++i) {
      ans.push_back(i);
    }
    vector<LL> ans2 = Solve(n - i, k);
    for (LL a : ans2) ans.push_back(i + a);
    for (LL a : ans) cout << a + 1 << " ";
    cout << '\n';
  }
  return 0;
}