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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  int times;
  cin >> times;
  while (times--) {
    cin >> n;
    LL m = n / 2050;
    if (m * 2050 != n) {
      cout << -1 << "\n";
      continue;
    }
    int ans = 0;
    while (m > 0) {
      ans += m % 10;
      m /= 10;
    }
    cout << ans << '\n';
  }
  return 0;
}