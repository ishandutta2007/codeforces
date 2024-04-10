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

class SegTree {
 public:
  SegTree(int _n): n(_n) {
    // Add how many times
    x = vector<LL>(_n * 4);
    // Delete something
    y = vector<LL>(_n * 4);
  }

  void PushDown(int t, int l, int r) {
    if (l == r) return;
    x[t + t] += x[t];
    x[t + t + 1] += x[t];
    x[t] = 0;
    y[t + t] += y[t];
    y[t + t + 1] += y[t];
    y[t] = 0;
  }

  void Insert(int t, LL a, int l, int r, int p, int q) {
    PushDown(t, l, r);
    if (p <= l && r <= q) {
      ++x[t];
      y[t] -= a;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) Insert(t + t, a, l, mid, p, q);
    if (mid + 1 <= q) Insert(t + t + 1, a, mid + 1, r, p, q);
  }

  void Clear(int t, int l, int r, int p) {
    PushDown(t, l, r);
    if (l == r) {
      x[t] = y[t] = 0;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) {
      Clear(t + t, l, mid, p);
    } else {
      Clear(t + t + 1, mid + 1, r, p);
    }
  }

  LL Query(int t, int l, int r, int p) {
    PushDown(t, l, r);
    if (l == r) {
      return x[t] * l + y[t];
    }
    int mid = (l + r) >> 1;
    if (p <= mid) return Query(t + t, l, mid, p);
    return Query(t + t + 1, mid + 1, r, p);
  }

  int n;
  vector<LL> x, y;
};

class BIT {
public:
  BIT(int _n): n(_n) {
    x = vector<LL>(_n);
  }

  void Insert(int a, LL b) {
    for (int i = a; i < n; i += (i & -i)) x[i] += b;
  }

  LL Query(int a) {
    LL ans = 0;
    for (int i = a; i > 0; i -= (i & -i)) ans += x[i];
    return ans;
  }

  int n;
  vector<LL> x;
};


const int MAXN = 200010;
const LL MAXS = 300000;

LL x[MAXN];
BIT bitc(MAXS + 10), bits(MAXS + 10);
LL ans[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i];
  bitc.Insert(x[0], 1);
  bits.Insert(x[0], x[0]);
  for (int i = 1; i < n; ++i) {
    LL precount = 0, presum = 0;
    LL diff = 0;
    for (LL j = x[i]; ; j += x[i]) {
      if (j > MAXS) j = MAXS + 1;
      LL count = bitc.Query(j - 1) - precount;
      LL sum = bits.Query(j - 1) - presum;
      ans[i] += sum - count * diff;
      precount += count;
      presum += sum;
      diff += x[i];
      if (j == MAXS + 1) break;
    }
    bitc.Insert(x[i], 1);
    bits.Insert(x[i], x[i]);
  }

  SegTree tree(MAXS);
  for (int i = n - 1; i >= 0; --i) {
    for (LL j = 0; j <= MAXS; j += x[i]) {
      if (j + x[i] - 1 == 0) continue;
      tree.Insert(1, j, 1, MAXS, j, j + x[i] - 1);
    }
    tree.Clear(1, 1, MAXS, x[i]);
  }
  for (int i = 0; i < n; ++i) ans[i] += tree.Query(1, 1, MAXS, x[i]);
  for (int i = 0; i < n; ++i) {
    if (i > 0) ans[i] += ans[i - 1];
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}