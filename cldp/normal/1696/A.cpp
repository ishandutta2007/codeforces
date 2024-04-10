#include <algorithm>
#include <bitset>
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
    int n, a;
    cin >> n >> a;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int b;
      cin >> b;
      ans = max(ans, b | a);
    }
    cout << ans << "\n";
  }
  return 0;
}