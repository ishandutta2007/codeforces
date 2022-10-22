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

int n;

vector<int> Ask(int a) {
  cout << "? " << a + 1 << endl;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  return x;
}

void Print(vector<pair<int, int>>& ans) {
  cout << "!" << endl;
  for (auto& [a, b] : ans) cout << a + 1 << " " << b + 1 << endl;
}


int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  vector<pair<int, int>> ans;
  vector<vector<int>> x(n);
  x[0] = Ask(0);
  int odd = 0, even = 0;
  for (int i = 1; i < n; ++i) {
    if (x[0][i] & 1) ++odd; else ++even;
    if (x[0][i] == 1) ans.push_back({0, i});
  }
  if (odd < even) {
    for (int i = 1; i < n; ++i) {
      if (x[0][i] % 2 == 0) continue;
      x[i] = Ask(i);
      for (int j = 1; j < n; ++j) {
        if (x[i][j] != 1) continue;
        if (x[0][j] == x[0][i] + 1 || x[0][j] + 1 == x[0][i]) {
          ans.push_back({i, j});
        }
      }
    }
  } else {
    for (int i = 1; i < n; ++i) {
      if (x[0][i] & 1) continue;
      x[i] = Ask(i);
      for (int j = 1; j < n; ++j) {
        if (x[i][j] != 1) continue;
        if (x[0][j] == x[0][i] + 1 || x[0][j] + 1 == x[0][i]) {
          ans.push_back({i, j});
        }
      }
    }
  }
  Print(ans);
  return 0;
}