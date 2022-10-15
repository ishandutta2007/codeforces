#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e6 + 7;
const int INF = (int) 1e9;
int n, m, a[N], b[N], y;

int aib[N];

void clr() {
  for (int i = 1; i <= y; i++) {
    aib[i] = 0;
  }
}

void add(int i, int x) {
  while (i <= y) {
    aib[i] += x;
    i += i & (-i);
  }
}

int get(int i) {
  int sol = 0;
  while (i) {
    sol += aib[i];
    i -= i & (-i);
  }
  return sol;
}

int type[N];

int tree[4 * N];
int lazy[4 * N];

void build(int v, int tl, int tr) {
  lazy[v] = 0;
  if (tl == tr) {
    tree[v] = tl;
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

void push(int v, int tl, int tr) {
  if (lazy[v] == 0) return;
  tree[v] += lazy[v];
  if (tl < tr) {
    lazy[2 * v] += lazy[v];
    lazy[2 * v + 1] += lazy[v];
  }
  lazy[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) return;
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  tree[v] = min(tree[2 * v], tree[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) return INF;
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void build() {
  build(1, 0, n);
}

void add(int l, int r, int x) {
  add(1, 0, n, l, r, x);
}

int get(int l, int r) {
  return get(1, 0, n, l, r);
}

int tra[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    vector<pair<int, int>> tr;

    for (int i = 1; i <= n; i++) {cin >> a[i]; tr.push_back({a[i], i});}
    for (int i = 1; i <= m; i++) cin >> b[i];
    sort(b + 1, b + m + 1);

    sort(tr.begin(), tr.end());
    y = 0;
    for (int i = 0; i < n; i++) {
      if (i == 0 || (i > 0 && tr[i].first != tr[i - 1].first)) y++;
      tra[tr[i].second] = y;
    }


    vector<int> ord;

    {
      vector<pair<int, int>> aso;
      for (int i = 1; i <= n; i++) {
        aso.push_back({a[i], i});
      }
      sort(aso.begin(), aso.end());
      for (auto &it : aso) {
        ord.push_back(it.second);
      }
    }

    clr();


    ll sol = 0;
    for (int i = n; i >= 1; i--) {
      sol += get(tra[i] - 1);
      add(tra[i], 1);
    }
    int p1 = 0, p2 = 0;

    for (int i = 1; i <= n; i++) {
      type[i] = +1;
    }
    build();
    int zu = 0;

    for (int j = 1; j <= m; j++) {
      while (p1 < n && a[ord[p1]] <= b[j]) {
        type[ord[p1]]--;
        add(ord[p1], n, -1);
        p1++;
      }
      while (p2 < n && a[ord[p2]] < b[j]) {
        type[ord[p2]]--;
        add(ord[p2], n, -1);
        zu++;
        p2++;
      }
      sol += get(0, n) + zu;
    }
    cout << sol << "\n";
  }


  return 0;
}
/**



**/