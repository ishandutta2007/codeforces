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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

class BIT {
public:
  BIT(int _n): n(_n) {
    x = vector<int>(_n);
  }

  void Insert(int a, int b) {
    for (int i = a; i < n; i += (i & -i)) x[i] += b;
  }

  int Query(int a) {
    int ans = 0;
    for (int i = a; i > 0; i -= (i & -i)) ans += x[i];
    return ans;
  }

  // If all elements are non-negative, returns the first position
  // with value >= v.
  int Search(int v) {
    int sum = 0;
    int pos = 0;
    // Needs log(n), usually 20 is enough.
    for (int i = 20; i >= 0; i--) {
      if (pos + (1 << i) < n && sum + x[pos + (1 << i)] < v) {
        sum += x[pos + (1 << i)];
        pos += (1 << i);
      }
    }
    return pos + 1;
  }

  int n;
  vector<int> x;
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; ++i) cin >> x[i];
    int ans = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        if (x[i] < x[j]) ++ans;
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}