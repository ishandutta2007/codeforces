#include <bits/stdc++.h>

using namespace std;

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

const int N = (int) 5e5 + 7;
const int INF = (int) 1e9;
int n, q, a[N], ret[N], ant[N], ultimul[N];
vector<pair<int, int>> ask[N];

int comb(int i, int j) {
  if (min(i, j) == 0) return max(i, j);
  if (ant[i] < ant[j]) return i;
  return j;
}

int t[4 * N];

void upd(int v, int tl, int tr, int i) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    t[v] = i;
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i);
  upd(2 * v + 1, tm + 1, tr, i);
  t[v] = comb(t[2 * v], t[2 * v + 1]);
}

void upd(int i, int val) {
  ant[i] = val;
  upd(1, 1, n, i);
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return comb(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int f(int l, int r) {
  int i = get(1, 1, n, l, r);
  if (ant[i] >= l) return 0;
  return a[i];
}


signed realMain() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    ask[r].push_back({l, i});
    ret[i] = -1;
  }
  for (int r = 1; r <= n; r++) {
    if (ultimul[a[r]]) {
      upd(ultimul[a[r]], INF);
    }
    upd(r, ultimul[a[r]]);
    ultimul[a[r]] = r;
    for (auto &it : ask[r]) {
      int l = it.first, i = it.second;
      ret[i] = f(l, r);
    }
  }
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << "\n";
  }
  return 0;
}