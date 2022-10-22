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
    int odd = (a + b) / 2, even = (a + b + 1) / 2;
    set<int> s;
    for (int i = 0; i <= a; ++i) {
      int ao = i;
      int ae = a - i;
      int bo = odd - ao;
      int be = even - ae;
      if (0 <= bo && bo <= b) {
        s.insert(ao + be);
        s.insert(ae + bo);
      }
    }
    cout << s.size() << "\n";
    for (int i : s) cout << i << " ";
    cout << "\n";
  }
  return 0;
}