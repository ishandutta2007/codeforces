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

const int MAXN = 1010;

int x[MAXN];

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  queue<pair<int, int>> x, y;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if ((i + j) % 2 == 0) {
        x.push({i + 1, j + 1});
      } else {
        y.push({i + 1, j + 1});
      }
    }
  }
  for (int i = 0; i < n * n; ++i) {
    int t;
    cin >> t;
    if (t == 1 || t == 3) {
      if (!x.empty()) {
        auto [a, b] = x.front();
        x.pop();
        cout << 2 << " " << a << " " << b << endl;
      } else {
        auto [a, b] = y.front();
        y.pop();
        cout << 4 - t << " " << a << " " << b << endl;
      }
    } else {
      if (!y.empty()) {
        auto [a, b] = y.front();
        y.pop();
        cout << 1 << " " << a << " " << b << endl;
      } else {
        auto [a, b] = x.front();
        x.pop();
        cout << 3 << " " << a << " " << b << endl;
      }
    }
  }
  return 0;
}