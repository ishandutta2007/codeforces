/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 2e5 + 10, mod = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += mod;
  }
  return a;
}

int mul(ll a, int b) {
  return (a * b) % mod;
}

struct task_t {
  int a, b, id;
};

int tree[8 * N];

void update(int i, int l, int r, int p, int val);
int query(int i, int l, int r, int ql, int qr);

int main() {
  fast_cin();
  int n; cin >> n;
  vector<task_t> t(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i].a >> t[i].b;
    t[i].id = i;
  }
  int nsz; cin >> nsz;
  vector<int> need(n + 1, 0);
  while (nsz--) {
    int x; cin >> x;
    need[x] = true;
  }
  vector<int> ids(n);
  iota(ids.begin(), ids.end(), 1);
  sort(ids.begin(), ids.end(), [&](int i, int j) {
    return t[i].b < t[j].b;
  });
  int pos = 1;
  reverse(ids.begin(), ids.end());
  vector<int> at(n + 1, -1);
  int ans = 0;
  for (auto& i : ids) {
    if (need[i]) {
      if (t[i].a < pos) {
        continue;
      } else {
        at[i] = pos;
        pos = t[i].a;
        ans = add(ans, 1);
      }
    }
  }
  reverse(ids.begin(), ids.end());
  for (auto& i : ids) {
    if (at[i] != -1) {
      ans = add(ans, query(1, 1, 2 * n, 1, at[i]));
    }
    int cur = query(1, 1, 2 * n, 1, t[i].a);
    cur = add(cur, 1);
    update(1, 1, 2 * n, 1, cur);
    update(1, 1, 2 * n, t[i].a + 1, (mod - cur) % mod);
  }
  cout << ans << '\n';
}

void update(int i, int l, int r, int p, int val) {
  if (p < l or p > r) {
    return;
  } else if (l == r) {
    tree[i] = add(tree[i], val);
  } else {
    int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
    update(lc, l, mid, p, val);
    update(rc, mid + 1, r, p, val);
    tree[i] = add(tree[lc], tree[rc]);
  }
}

int query(int i, int l, int r, int ql, int qr) {
  if (l > qr or ql > r) {
    return 0;
  } else if (ql <= l and r <= qr) {
    return tree[i];
  } else {
    int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
    auto q1 = query(lc, l, mid, ql, qr);
    auto q2 = query(rc, mid + 1, r, ql, qr);
    return add(q1, q2);
  }
}