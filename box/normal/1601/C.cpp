#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int a[1000006], b[1000006];
ll cnt_inv(int n) {
  vector<int> fen(n + 1), sor(a, a + n);
  sort(all(sor));
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int p = lower_bound(all(sor), a[i]) - sor.begin() + 1;
    int c = p;
    ans += i;
    while (c) {
      ans -= fen[c];
      c -= (c & (-c));
    }
    while (p <= n) {
      fen[p]++;
      p += (p & (-p));
    }
  }
  return ans;
}
int seg[1000006 << 2], lazy[1000006 << 2];
void build(int idx, int l, int r) {
  if (r - l == 1) {
    seg[idx] = l;
    return;
  }
  build(idx * 2, l, (l + r) / 2);
  build(idx * 2 + 1, (l + r) / 2, r);
  seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
}
void tag(int idx, int l, int r, int v) {
  lazy[idx] += v;
  seg[idx] += v;
}
void pd(int idx, int l, int r) {
  if (r - l == 1 || !lazy[idx])
    return;
  tag(idx * 2, l, (l + r) / 2, lazy[idx]);
  tag(idx * 2 + 1, (l + r) / 2, r, lazy[idx]);
  lazy[idx] = 0;
}
void add(int idx, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R)
    return tag(idx, l, r, v);
  if (R <= l || r <= L)
    return;
  pd(idx, l, r);
  add(idx * 2, l, (l + r) / 2, L, R, v);
  add(idx * 2 + 1, (l + r) / 2, r, L, R, v);
  seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
}
int qmin(int idx, int l, int r, int L, int R) {
  if (L <= l && r <= R)
    return seg[idx];
  if (R <= l || r <= L)
    return 1e9;
  pd(idx, l, r);
  return min(qmin(idx * 2, l, (l + r) / 2, L, R),
             qmin(idx * 2 + 1, (l + r) / 2, r, L, R));
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pii> pos(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[i] = {a[i], i};
    }
    sort(all(pos));
    ll ans = cnt_inv(n);
    for (int j = 0; j < m; j++) {
      cin >> b[j];
    }
    for (int i = 0; i <= (n + 3) * 4; i++)
      seg[i] = lazy[i] = 0;
    sort(b, b + m);
    build(1, 0, n + 1);
    int cur1 = 0, cur2 = 0;
    for (int i = 0; i < m; i++) {
      int r = b[i];
      while (cur1 != n && pos[cur1].fi < r) {
        int s = pos[cur1].se;
        add(1, 0, n + 1, 0, s, 1);
        cur1++;
      }
      while (cur2 != n && pos[cur2].fi <= r) {
        int s = pos[cur2].se;
        add(1, 0, n + 1, s + 1, n + 1, -1);
        cur2++;
      }
      ans += seg[1];
    }
    cout << ans << endl;
  }
}