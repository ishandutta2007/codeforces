#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
const int INF = (int) 1e9 + 1;
int n, m, restr[4 * N], type[N], locked[N];
vector<int> q[N];

void impose(int v, int tl, int tr, int l, int r, int x) {
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    restr[v] = min(restr[v], x);
    return;
  }
  int tm = (tl + tr) / 2;
  impose(2 * v, tl, tm, l, r, x);
  impose(2 * v + 1, tm + 1, tr, l, r, x);
}

int getImposed(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) return INF;
  if (tl == tr) return restr[v];
  int tm = (tl + tr) / 2;
  return min(restr[v], min(getImposed(2 * v, tl, tm, i), getImposed(2 * v + 1, tm + 1, tr, i)));
}

int tmax[4 * N];

void upd(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    tmax[v] = x;
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, x);
  upd(2 * v + 1, tm + 1, tr, i, x);
  tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
}

int getm(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return -INF;
  if (l <= tl && tr <= r) return tmax[v];
  int tm = (tl + tr) / 2;
  return max(getm(2 * v, tl, tm, l, r), getm(2 * v + 1, tm + 1, tr, l, r));
}

bool act[N];

int lg(int x) {
  if (x >= 2) return 1 + lg(x / 2);
  return 0;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  for (int i = 0; i < 4 * N; i++) {
    restr[i] = INF;
  }

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    locked[i] = -1;
  }

  for (int i = 1; i <= m; i++) {
    cin >> type[i];
    if (type[i] == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      impose(1, 1, n, l, r, x);
      q[i] = {l, r, x};
    } else {
      int k, x;
      cin >> k >> x;
      if (locked[k] == -1) {
        locked[k] = getImposed(1, 1, n, k);
      }
      q[i] = {k, x};
    }
  }
  for (int i = 1; i <= n; i++) {
    locked[i] = ((locked[i] == -1) ? getImposed(1, 1, n, i) : locked[i]);
    upd(1, 1, n, i, locked[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (type[i] == 1) {
      int l = q[i][0], r = q[i][1], x = q[i][2];
      if (getm(1, 1, n, l, r) != x) {
        cout << "NO\n";
        return 0;
      }
    } else {
      int k = q[i][0], x = q[i][1];
      upd(1, 1, n, k, x);
    }
  }
  cout << "YES\n";
  map<int, int> f;
  map<int, int> some;
  for (int i = 1; i <= n; i++) {
   // cout << i << " : " << locked[i] << "\n";
    f[locked[i]]++;
    some[locked[i]] = i;
  }
  for (auto &it : f) {
    if (it.second >= 2) {
      int x = it.first, ind = some[x];
      x = lg(x);
      x = (1 << x) - 1;
      locked[ind] = x;
    }
  }
  int lm = 0;
  for (int i = 1; i <= n; i++) {
    if (locked[i] < INF) lm |= locked[i];
  }
  for (int i = 1; i <= n; i++) {
    if (locked[i] == INF) {
      locked[i] = 0;
      for (int bit = 30; bit >= 0; bit--) {
        if (locked[i] + (1 << bit) < INF && (!(lm & (1 << bit)))) {
          lm |= (1 << bit);
          locked[i] |= (1 << bit);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << locked[i] << " ";
  }
  cout << "\n";
  return 0;
}