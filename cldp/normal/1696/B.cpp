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
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int j = i;
      while (j < n && x[j] == 0) ++j;
      if (j == n) break;
      while (j < n && x[j] != 0) ++j;
      ++cnt;
      i = j;
    }
    if (cnt >= 2) cnt = 2;
    cout << cnt << "\n";
  }
  return 0;
}