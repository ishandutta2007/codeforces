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
    int n, l, r;
    cin >> n >> l >> r;
    map<int, int> x;
    for (int i = 0; i < l; ++i) {
      int a;
      cin >> a;
      ++x[a];
    }
    for (int i = 0; i < r; ++i) {
      int a;
      cin >> a;
      --x[a];
    }
    int sumL = 0, sumR = 0;
    for (auto& [a, b] : x) {
      if (b == 0) continue;
      if (b > 0) {
        sumL += b;
      } else {
        sumR -= b;
      }
    }
    int ans = 0;
    if (sumL > sumR) {
      for (auto& [a, b] : x) {
        while (b > 1 && sumL > sumR) {
          b -= 2;
          ++ans;
          sumL -= 2;
        }
        if (sumL == sumR) break;
      }
    } else
    if (sumR > sumL) {
      for (auto& [a, b] : x) {
        while (b < -1 && sumL < sumR) {
          b += 2;
          ++ans;
          sumR -= 2;
        }
        if (sumL == sumR) break;
      }
    }
    cout << ans + max(sumL, sumR) << '\n';
  }
  return 0;
}