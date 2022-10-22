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

const int MAXN = 200010;

vector<int> x[MAXN];
int f[MAXN];
int realleave, leave, hud;

void DP(int a, int fa) {
  int cnthud = 0, cntleave = 0;
  for (int b : x[a]) {
    if (b == fa) continue;
    DP(b, a);
    if (f[b] == 1) ++cnthud; else ++cntleave;
  }
  if (cntleave == 0) {
    f[a] = 2;
  } else {
    f[a] = 1;
    if (a == 0) {
      realleave += cntleave;
    } else {
      ++hud;
      leave += cntleave;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      x[i].clear();
      f[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      x[a].push_back(b);
      x[b].push_back(a);
    }
    realleave = leave = hud = 0;
    DP(0, -1);
    if (realleave != 0) {
      cout << realleave + leave - hud << "\n";
    } else {
      cout << leave - (hud - 1) << "\n";
    }
  }
  return 0;
}