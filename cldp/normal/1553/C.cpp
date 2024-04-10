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
    string s;
    cin >> s;
    int ans = 10;
    for (int i = 0; i < (1 << 10); ++i) {
      bool flag = true;
      for (int j = 0; j < 10; ++j) {
        if (s[j] == '?') continue;
        if (s[j] != '0' + (i >> j & 1)) flag = false;
      }
      if (!flag) continue;
      int a = 0, b = 0;
      for (int j = 0; j < 10; j += 2) {
        a += (i >> j & 1);
        if (a > b + (10 - j) / 2 || b > a + (8 - j) / 2) {
          ans = min(ans, j + 1); 
          break;
        }
        b += (i >> (j + 1) & 1);
        if (b > a + (8 - j) / 2 || a > b + (8 - j) / 2) {
          ans = min(ans, j + 2);
          break;
        }
      } 
    }
    cout << ans << "\n";
  }
  return 0;
}