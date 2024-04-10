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

const int MAXN = 100010;

int p[3][MAXN];
int st[MAXN];
int f[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i <= n; ++i) f[i] = 0;
    for (int i = 0; i < n; ++i) {
      p[0][i + 1] = p[0][i];
      p[1][i + 1] = p[1][i];
      p[2][i + 1] = p[2][i];
      st[i] = (s[i] - '0') + (t[i] - '0');
      if (st[i] == 0) p[0][i + 1] = i + 1;
      if (st[i] == 1) p[1][i + 1] = i + 1;
      if (st[i] == 2) p[2][i + 1] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
      if (st[i] == 0) {
        f[i + 1] = f[i] + 1;
        int pos = max(p[1][i + 1], p[2][i + 1]);
        if (pos == 0) continue;
        f[i + 1] = max(f[i + 1], f[pos - 1] + 2);
      } else
      if (st[i] == 1) {
        f[i + 1] = f[i] + 2;
      } else {
        f[i + 1] = f[i];
        int pos = max(p[0][i + 1], p[1][i + 1]);
        if (pos == 0) continue;
        f[i + 1] = max(f[i + 1], f[pos - 1] + 2);
      }
    }
    cout << f[n] << "\n";
  }
  return 0;
}