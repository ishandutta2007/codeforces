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

const int MAXN = 303;

bool z[MAXN][MAXN];
int x[MAXN][MAXN];
vector<int> pos[MAXN * MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    map<int, int> h;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> x[i][j];
        h[x[i][j]] = 0;
      }
    }
    int nn = 0;
    for (auto& [a, b] : h) {
      b = ++nn;
      pos[nn].clear();
    }
    vector<int> y;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        x[i][j] = h[x[i][j]];
        y.push_back(x[i][j]);
      }
    }
    sort(y.begin(), y.end());
    for (int i = 0; i < y.size(); ++i) {
      pos[y[i]].push_back(i);
    }
    for (int i = 1; i <= nn; ++i) {
      sort(pos[i].begin(), pos[i].end(), [&](const int& a, const int &b) {
        if (a / m != b / m) return a / m < b / m;
        return a % m > b % m;
      });
      reverse(pos[i].begin(), pos[i].end());
    }
    int ans = 0;
    memset(z, 0, sizeof(z));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int p = pos[x[i][j]].back() / m, q = pos[x[i][j]].back() % m;
        pos[x[i][j]].pop_back();
        for (int j = 0; j < q; ++j) ans += z[p][j];
        z[p][q] = true;
      }
    }
    cout << ans << "\n";
  }
  
  return 0;
}