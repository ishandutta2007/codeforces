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

LL Solve(int start, vector<int>& x) {
  LL ans = 0;
  int j = 0;
  for (int i = 0; i < x.size(); i += 2) {
    while (j < x.size() && x[j] != start) ++j;
    ans += abs(j - i);
    ++j;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    vector<int> x(n);
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      x[i] %= 2;
      if (x[i] & 1) ++odd; else ++even;
    }
    if (odd == even) {
      LL ans = min(Solve(0, x), Solve(1, x));
      cout << ans << "\n";
    } else
    if (odd + 1 == even) {
      cout << Solve(0, x) << "\n";
    } else
    if (odd == even + 1) {
      cout << Solve(1, x) << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}