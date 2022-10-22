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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    cout << 3 * n << '\n';
    for (int i = 1; i <= n; i += 2) {
      cout << 1 << " " << i << " " << i + 1 << '\n';
      cout << 2 << " " << i << " " << i + 1 << '\n';
      cout << 2 << " " << i << " " << i + 1 << '\n';
      cout << 1 << " " << i << " " << i + 1 << '\n';
      cout << 2 << " " << i << " " << i + 1 << '\n';
      cout << 2 << " " << i << " " << i + 1 << '\n';
    }
  }
  return 0;
}