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

struct Node {
  LL h;
  int i, ans;
  bool operator<(const Node& t) const {
    return h > t.h;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Node> x;
    for (int i = 0; i < n; ++i) {
      LL a;
      cin >> a;
      x.push_back({a, i, 0});
    }
    set<pair<LL, int>> s;
    for (int i = 0; i < m; ++i) {
      s.insert({0, i});
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
      auto [a, b] = *s.begin();
      s.erase(*s.begin());
      a += x[i].h;
      x[i].ans = b;
      s.insert({a, b});
    }
    sort(x.begin(), x.end(), [](const Node& a, const Node& b) {
      return a.i < b.i;
    });
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << x[i].ans + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}