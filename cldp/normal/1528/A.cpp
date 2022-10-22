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
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

const int MAXN = 100010;

LL l[MAXN], r[MAXN];
LL f[MAXN][2];
vector<int> x[MAXN];

void Solve(int a, int fa) {
  for (int b : x[a]) {
    if (b == fa) continue;
    Solve(b, a);
    f[a][0] += max(f[b][0] + abs(l[b] - l[a]), f[b][1] + abs(r[b] - l[a]));
    f[a][1] += max(f[b][0] + abs(l[b] - r[a]), f[b][1] + abs(r[b] - r[a]));
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
      cin >> l[i] >> r[i];
      x[i].clear();
      f[i][0] = f[i][1] = 0;
    }
    for (int i = 1; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      x[a].push_back(b);
      x[b].push_back(a);
    }
    Solve(0, -1);
    cout << max(f[0][0], f[0][1]) << '\n';
  }
  return 0;
}