#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int ll

struct T {
  int mn;
  int mx;
  T() {
    mn = (int) 1e18;
    mx = -(int) 1e18;
  }
};

T operator + (T a, T b) {
  a.mn = min(a.mn, b.mn), a.mx = max(a.mx, b.mx);
  return a;
}

const int N = (int) 1e5 + 7;
T t[4 * N];
int n, ret, a[N], l[N], r[N], sum[N];
vector<int> stk;

void build(int v, int tl, int tr) {
  if (tl == tr) t[v].mn = t[v].mx = sum[tl];
  else {
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm), build(2 * v + 1, tm + 1, tr);
    t[v] = t[2 * v] + t[2 * v + 1];
  }
}

T get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) {
    T nothing;
    return nothing;
  }
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

void build() {
  build(1, 0, n);
}

T get(int l, int r) {
  return get(1, 0, n, l, r);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {cin >> a[i]; sum[i] = sum[i - 1] + a[i];}
  stk = {};
  for (int i = 1; i <= n; i++) {
    while (!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
    if (stk.empty()) l[i] = 1; else l[i] = stk.back() + 1;
    stk.push_back(i);
  }
  stk = {};
  for (int i = n; i >= 1; i--) {
    while (!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
    if (stk.empty()) r[i] = n; else r[i] = stk.back() - 1;
    stk.push_back(i);
  }
  /// bob deletes the maximum element
  /// answer = maximum over all segments l, r : sum(l...r) - max(l...r)
  build();
  for (int id = 1; id <= n; id++) ret = max(ret, get(id, r[id]).mx - get(l[id] - 1, id - 1).mn - a[id]);
  cout << ret << "\n";
}