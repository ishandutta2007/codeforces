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

int f[1 << 15];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) x[i] = i;
  vector<LL> mask(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') mask[i] |= (1LL << j);
    }
  }
  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(x.begin(), x.end(), g);
  int ans = 0;
  string anss;
  for (int times = 0; times < 50; ++times) {
    int t = x[rand() % n];
    memset(f, 0, sizeof(f));
    vector<int> pos;
    for (int i = 0; i < m; ++i) {
      if (mask[t] >> i & 1) pos.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < pos.size(); ++j) {
        if (mask[i] >> pos[j] & 1) sum |= (1 << j);
      }
      ++f[sum];
    }
    for (int i = 0; i < p; ++i) {
      for (int j = (1 << p) - 1; j >= 0; --j) {
        if (j >> i & 1) f[j ^ (1 << i)] += f[j];
      }
    }
    for (int i = 0; i < (1 << p); ++i) {
      if (f[i] >= (n + 1) / 2 && __builtin_popcount(i) > ans) {
        ans = __builtin_popcount(i);
        anss.clear();
        for (int j = 0; j < m; ++j) anss.push_back('0');
        for (int j = 0; j < p; ++j) {
          if (i >> j & 1) anss[pos[j]] = '1';
        }
      }
    }
  }
  cout << anss << endl;  
  return 0;
}