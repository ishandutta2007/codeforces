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

const int MAXN = 300010;

int n, m;
int x[MAXN];
int f[MAXN];
int xx[MAXN];


bool Validate(int p) {
  for (int i = 0; i < n; ++i) {
    xx[i] = x[(i + p) % n];
  }
  int cnt = m;
  for (int i = 0; i < n; ++i) {
    while (i != xx[i]) {
      if (cnt == 0) return false;
      swap(xx[i], xx[xx[i]]);
      --cnt;
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      --x[i];
      f[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
      if (x[i] <= i) {
        ++f[i - x[i]];
      } else {
        ++f[i + n - x[i]];
      }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (f[i] >= n - m * 2) {
        if (Validate(i)) ans.push_back(i);
      }
    }
    cout << ans.size() << " ";
    for (int i : ans) cout << i << " ";
    cout << "\n";
  }
  
  return 0;
}