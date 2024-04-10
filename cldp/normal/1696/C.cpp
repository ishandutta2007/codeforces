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
    int n, m;
    cin >> n >> m;
    vector<pair<LL, LL>> x;
    for (int i = 0; i < n; ++i) {
      LL a, b = 1;
      cin >> a;
      while (a % m == 0) {
        a /= m;
        b *= m;
      }
      if (!x.empty() && x.back().first == a) {
        x.back().second += b;
      } else {
        x.push_back({a, b});
      }
    }
    int k;
    cin >> k;
    vector<pair<LL, LL>> y;
    for (int i = 0; i < k; ++i) {
      LL a, b = 1;
      cin >> a;
      while (a % m == 0) {
        a /= m;
        b *= m;
      }
      if (!y.empty() && y.back().first == a) {
        y.back().second += b;
      } else {
        y.push_back({a, b});
      }
    }
    if (x == y) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
  return 0;
}