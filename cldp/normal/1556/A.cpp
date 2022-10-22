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
    int a, b;
    cin >> a >> b;
    if ((a + b) % 2 != 0) {
      cout << -1 << "\n";
      continue;
    }
    if (a == 0 && b == 0) {
      cout << 0 << "\n";
      continue;
    }
    if (a == b) {
      cout << 1 << "\n";
      continue;
    }
    cout << 2 << "\n";
  }
  return 0;
}