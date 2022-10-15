#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home = 1;

const int N = (int)2e5 + 7;
int n;
int par[N];
int edgeid[N];
int sub[N];
vector<pair<int, int>> gigi[N];
vector<int> g[N];
bool con[N];

void build(int a, int p = 0) {
  sub[a] = 1;
  par[a] = p;
  assert(0 <= p && p <= n);
  vector<int> kids;
  for (auto& it : gigi[a]) {
    int b = it.first, i = it.second;
    if (b != p) {

      build(b, a);
      edgeid[b] = i;
      sub[a] += sub[b];

      kids.push_back(b);
    }
  }
  g[a] = kids;
  if (kids.empty()) {
    return;
  }
  int mx = 0;
  for (auto& b : kids) {
    mx = max(mx, sub[b]);
  }
  bool f = 0;
  for (auto& b : kids) {
    if (mx == sub[b]) {
      con[b] = 1;
      f = 1;
      break;
    }
  }
  assert(f);
}

int color[N], cntusedcols, id[N], ids, fnode[N];

void dfs(int a, int curcol) {
  if (!fnode[curcol]) {
    fnode[curcol] = a;
  }
  id[a] = ++ids;
  color[a] = curcol;
  for (auto& b : g[a]) {
    if (con[b]) {
      dfs(b, curcol);
    }
  }
  for (auto& b : g[a]) {
    if (!con[b]) {
      dfs(b, ++cntusedcols);
    }
  }
}


struct T {
  int cnt[2];
  ll s[2];
};

T operator + (T a, T b) {
  a.cnt[0] += b.cnt[0];
  a.cnt[1] += b.cnt[1];
  a.s[0] += b.s[0];
  a.s[1] += b.s[1];
  return a;
}

T t[4 * N];
bool lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    swap(t[v].s[0], t[v].s[1]);
    swap(t[v].cnt[0], t[v].cnt[1]);
    if (tl < tr) {
      lazy[2 * v] ^= 1;
      lazy[2 * v + 1] ^= 1;
    }
    lazy[v] = 0;
  }
}

void xorate(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] ^= 1;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  xorate(2 * v, tl, tm, l, r);
  xorate(2 * v + 1, tm + 1, tr, l, r);
  t[v] = t[2 * v] + t[2 * v + 1];
}

void activate(int v, int tl, int tr, int i, ll x) {
  push(v, tl, tr);
  if (tr < i || i < tl) {
    return;
  }
  if (tl == tr) {
    assert(t[v].s[0] == 0);
    assert(t[v].s[1] == 0);
    assert(t[v].cnt[0] == 0);
    assert(t[v].cnt[1] == 0);
    t[v].s[0] = x;
    t[v].cnt[0]++;
    return;
  }
  int tm = (tl + tr) / 2;
  activate(2 * v, tl, tm, i, x);
  activate(2 * v + 1, tm + 1, tr, i, x);
  t[v] = t[2 * v] + t[2 * v + 1];
}

T mt;

T get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return mt;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

void xorToRoot(int a) {
  activate(1, 1, n, id[a], edgeid[a]);
  while (a) {
    int b = fnode[color[a]];
    xorate(1, 1, n, id[b], id[a]);
    a = par[b];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {

  }


  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    gigi[a].push_back({ b,i });
    gigi[b].push_back({ a,i });
  }
  build(1);
  dfs(1, ++cntusedcols);


  int vrt = 0;

  xorToRoot(1); vrt++;

  bool isok = 0;

  while (1) {
    int task;
    cin >> task;
    assert(1 <= task && task <= 3);
    if (task == 1) {
      int v;
      cin >> v;
      push(1, 1, n);
      xorToRoot(v); vrt++;
      isok = 1;
      isok &= (get(1, 1, n, id[1], id[1]).cnt[0] > 0);
      int c0 = 0, c1 = 0;
      ll thesum = 0;
      c0 = t[1].cnt[0];
      c1 = t[1].cnt[1];
      thesum = t[1].s[1];
      isok &= (c0 == c1);
      if (!isok) {
        cout << "0" << endl;
      }
      else {
        cout << thesum << endl;
      }
    }
    if (task == 2) {
      if (!isok) {
        cout << "0" << endl;
      }
      else {

        cout << vrt / 2 << " ";
        vector<int> e;

        for (int i = 1; i <= n; i++) {
          if (get(1, 1, n, id[i], id[i]).cnt[1] > 0) {
            e.push_back(edgeid[i]);
          }
        }
        sort(e.begin(), e.end());
        for (auto& i : e) {
          cout << i << " ";
        }
        cout << endl;
      }
    }
    if (task == 3) {
      break;
    }
  }

  return 0;
}