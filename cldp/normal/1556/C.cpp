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
  int n;
  cin >> n;
  vector<LL> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  unsigned long long ans = 0;
  for (int i = 0; i + 1 < n; i += 2) {
    if (x[i] < x[i + 1]) {
      ans += x[i];
      continue;
    }
    ans += x[i + 1];
    LL left = 0;
    LL premin = x[i] - x[i + 1];
    for (int j = i + 2; j < n; ++j) {
      if (j & 1) {
        if (left > x[j]) {
          left -= x[j];
          continue;
        }
        if (left == x[j]) {
          ++ans;
          left = 0;
          continue;
        }
        if (x[j] - left > premin) {
          ans += premin + 1;
          break;
        }
        ans += x[j] - left + 1;
        premin -= x[j] - left;
        left = 0;
      } else {
        left += x[j];
      }
    }
  }
  cout << ans << endl; 
  return 0;
}