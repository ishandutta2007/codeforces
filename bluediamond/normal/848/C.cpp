#include <bits/stdc++.h>

using namespace std;

//#define int long long
typedef long long ll;
bool home = 1;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 1e5 + 7;
int n, q, a[N];
ll tot[4 * N];
set<int> s[N];
pair<int, int> last[N];
unordered_map<int, ll> tree[4 * N];

void upd(int v, int tl, int tr, int i, int sgn) {
  if (tr < i || i < tl) {
    return;
  }
  tot[v] += sgn * last[i].second;
  for (int j = last[i].first; j <= n; j += j & (-j)) {
    tree[v][j] += sgn * last[i].second;
    if (!tree[v][j]) {
      tree[v].erase(j);
    }
  }
  if (tl < tr) {
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i, sgn);
    upd(2 * v + 1, tm + 1, tr, i, sgn);
  }
}

ll get(int v, int tl, int tr, int l, int r, int over) {
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) {
    ll ret = 0;
    for (int j = over; j > 0; j -= j & (-j)) {
      if (tree[v].count(j)) {
        ret += tree[v][j];
      }
    }
    return tot[v] - ret;
  }
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r, over) + get(2 * v + 1, tm + 1, tr, l, r, over);
}

ll get(int l, int r, int over) {
  return get(1, 1, n, l, r, over);
}

void upd(int i, int sgn) {
  if (last[i].first == 0) return;
  upd(1, 1, n, i, sgn);
}

signed realMain() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!s[a[i]].empty()) {
      auto it = s[a[i]].end();
      it--;
      last[i] = {*it, i - *it};
    } else {
      last[i] = {0, 0};
    }
    s[a[i]].insert(i);
    upd(i, +1);
  }
  for (int it = 1; it <= q; it++) {
    int type;
    cin >> type;
    if (type == 1) {
      int p, x;
      cin >> p >> x;
      auto it = s[a[p]].find(p);
      it++;
      if (it != s[a[p]].end()) {
        int i = *it;
        upd(i, -1);
        if (p == *s[a[p]].begin()) {
          last[i] = {0, 0};
        } else {
          it--;
          it--;
          last[i] = {*it, i - *it};
        }
        upd(i, +1);
      }
      s[a[p]].erase(p);
      a[p] = x;
      s[a[p]].insert(p);
      it = s[a[p]].find(p);
      it++;
      if (it != s[a[p]].end()) {
        int i = *it;
        upd(i, -1);
        last[i] = {p, i - p};
        upd(i, +1);
      }
      it--;
      upd(p, -1);
      if (it != s[a[p]].begin()) {
        it--;
        last[p] = {*it, p - *it};
      } else {
        last[p] = {0, 0};
      }
      upd(p, +1);
    } else {
      int l, r;
      cin >> l >> r;
      cout << get(l, r, l - 1) << "\n";
    }
  }
  return 0;
}