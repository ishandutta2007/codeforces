#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 5e5 + 7;
const int K = 20;
string s;
int n, f[N], c[N], ord[N], lcp[N], lg[N];
int tab[K][N];

int getlcp(int x, int y) {
  x = c[x];
  y = c[y];
  assert(x != y);
  if (x > y) swap(x, y);
  x++;
  int k = lg[y - x + 1];
  return min(tab[k][x], tab[k][y - (1 << k) + 1]);
}

struct T {
  int i;
  int c1;
  int c2;
};

vector<T> so(vector<T> v) {
  int n = (int) v.size();
  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    f[v[i].c2]++;
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  vector<T> v2(n);
  for (int i = n - 1; i >= 0; i--) {
    v2[--f[v[i].c2]] = v[i];
  }
  for (int i = 0; i <= n; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    f[v2[i].c1]++;
  }
  for (int i = 1; i <= n; i++) {
    f[i] += f[i - 1];
  }
  for (int i = n - 1; i >= 0; i--) {
    v[--f[v2[i].c1]] = v2[i];
  }
  return v;
}

bool operator < (T a, T b) {
  if (a.c1 != b.c1) {
    return a.c1 < b.c1;
  } else {
    return a.c2 < b.c2;
  }
}

void stuff() {
  for (int i = 2; i < N; i++) {
    lg[i] = 1 + lg[i / 2];
  }
  s += "$";
  n = (int) s.size();
  for (int i = 0; i < n; i++) {
    c[i] = s[i];
    f[c[i]]++;
  }
  for (int i = 1; i < N; i++) {
    f[i] += f[i - 1];
  }
  for (int i = 0; i < n; i++) {
    ord[--f[c[i]]] = i;
  }
  map<int, int> trn;
  for (int i = 0; i < n; i++) {
    trn[c[i]] = 0;
  }
  int curtrn = 0;
  for (auto &it : trn) {
    it.second = curtrn++;
  }
  for (int i = 0; i < n; i++) {
    c[i] = trn[c[i]];
  }
  for (int len = 1; len <= n; len *= 2) {
    vector<T> v;
    for (int i = 0; i < n; i++) {
      v.push_back({i, c[i], c[(i + len) % n]});
    }
    v = so(v);
    for (int i = 0; i < n; i++) {
      ord[i] = v[i].i;
    }
    c[v[0].i] = 0;
    for (int i = 1; i < n; i++) {
      c[v[i].i] = c[v[i - 1].i] + (v[i - 1] < v[i]);
    }
  }
  int k = 0;
  for (int i = 0; i < n - 1; i++) {
    int pi = c[i];
    int j = ord[pi - 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) {
      k++;
    }
    lcp[pi] = k;
    k = max(k - 1, 0);
  }
  s.pop_back();
  for (int i = 0; i <= n; i++) {
    tab[0][i] = lcp[i];
  }
  for (int k = 1; (1 << k) <= n; k++) {
    for (int i = 0; i + (1 << k) - 1 <= n; i++) {
      tab[k][i] = min(tab[k - 1][i], tab[k - 1][i + (1 << (k - 1))]);
    }
  }
}

int t[4 * N];

void upd(int v, int tl, int tr, int i, int x) {
  if (tr < i || i < tl) return;
  if (tl == tr) {
    t[v] = x;
    return;
  }
  int tm = (tl + tr) / 2;
  upd(2 * v, tl, tm, i, x);
  upd(2 * v + 1, tm + 1, tr, i, x);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  if (tr < l || r < tl) return 0;
  if (l <= tl && tr <= r) return t[v];
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r) {
  return get(1, 0, n, l, r);
}

int last;

int dp[N], pos;

bool ok(int where) {
  if (dp[where] == 1) {
    return 1;
  }
  while (last > where + dp[where]) {
    last--;
    upd(1, 0, n, c[last], dp[last]);
  }
  for (int i = where; i <= where + 1; i++) {
    int j = c[i], l = 0, r = j - 1, ff = j, ss = j;
    while (l <= r) {
      int m = (l + r) / 2;
      if (getlcp(i, ord[m]) >= dp[where] - 1) {
        ff = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    l = j + 1, r = n - 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (getlcp(i, ord[m]) >= dp[where] - 1) {
        ss = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if (get(ff, ss) >= dp[where] - 1) {
      return 1;
    }
  }
  return 0;
}

signed realMain() {
  int n, ret = 0;
  cin >> n >> s;
  stuff();
  last = n;
  assert((int) s.size() == n);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = dp[i + 1] + 1;
    while (!ok(i)) {
      dp[i]--;
    }
    ret = max(ret, dp[i]);
  }
  cout << ret << "\n";
  return 0;
}