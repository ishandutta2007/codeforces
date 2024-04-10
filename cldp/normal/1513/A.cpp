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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, k;
    cin >> n >> k;
    if ((n - 1) / 2 < k) {
      cout << -1 << endl;
      continue;
    }
    vector<int> x(n);
    int t = 1;
    for (int i = 0; i <= k + k; i += 2) {
      x[i] = t;
      ++t;
    }
    for (int i = 1; i < k + k; i += 2) {
      x[i] = t;
      ++t;
    }
    for (int i = k + k + 1; i < n; ++i) {
      x[i] = t;
      ++t;
    }
    for (int i = 0; i < n; ++i) cout << x[i] << " ";
    cout << endl;
  }
  return 0;
}