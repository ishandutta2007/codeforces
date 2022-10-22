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
  int times;
  cin >> times;
  while (times--) {
    LL n;
    cin >> n;
    bool flag = false;
    for (LL i = 1; i * i * 2 <= n; ++i) {
      if (2 * i * i == n || 4 * i * i == n) {
        flag = true;
        break;
      }
    }
    if (flag) cout << "YES\n"; else cout << "NO\n";
  }
  return 0;
}