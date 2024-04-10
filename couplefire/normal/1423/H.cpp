#include <bits/stdc++.h>
using namespace std;

const int MAXN = 700005;

int N, Q, K;
int ans[MAXN];
vector<array<int, 3>> operations[2 * MAXN];

int sz[MAXN];
int par[MAXN];
vector<array<int, 4>> hist;

int Find(int x) {
  return par[x] == x ? x : Find(par[x]);
}

int Unite(int x, int y) {
  x = Find(x), y = Find(y);
  if (x == y) {
    return 0;
  }
  if (sz[x] > sz[y]) {
    swap(x, y);
  }
  hist.push_back({x, y, par[x], sz[y]});
  par[x] = y;
  sz[y] += sz[x];
  return 1;
}

void Rollback(int x) {
  while (x--) {
    sz[hist.back()[1]] = hist.back()[3];
    par[hist.back()[0]] = hist.back()[2];
    hist.pop_back();
  }
}

int Query(int x) {
  return sz[Find(x)];
}

void Insert(int n, int tl, int tr, int t, int l, int r, int u, int v) {
  if (l > tr || tl > r || tl > tr || l > r) return;
  if (l <= tl && tr <= r) {
    operations[n].push_back({t, u, v});
    return;
  }
  int md = (tl + tr) / 2;
  int z = n + 2 * (md - tl + 1);
  Insert(n + 1, tl, md, t, l, r, u, v);
  Insert(z, md + 1, tr, t, l, r, u, v);
}

void Add(int u, int v, int t, int l, int r) {
  Insert(1, 0, Q - 1, t, l, r, u, v);
}

void Dfs(int n, int tl, int tr) {
  int ops = 0;
  for (auto &op : operations[n]) {
    if (op[0] == 0) {
      ops += Unite(op[1], op[2]);
    } else {
      ans[op[2]] = Query(op[1]);
    }
  }

  if (tl != tr) {
    int md = (tl + tr) / 2;
    int z = n + 2 * (md - tl + 1);
    Dfs(n + 1, tl, md);
    Dfs(z, md + 1, tr);
  }

  Rollback(ops);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q >> K;

  fill(sz, sz + MAXN, 1);
  iota(par, par + MAXN, 0);
  memset(ans, -1, sizeof(ans));

  vector<array<int, 3>> queries;
  vector<int> days(MAXN, Q);
  days[0] = 0;
  for (int i = 0, d = 0; i < Q; i++) {
    int t, x = -1, y = -1;
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      x--, y--;
    } else if (t == 2) {
      cin >> x;
      x--;
    } else {
      d++;
      days[d] = i + 1;
    }
    queries.push_back({t, x, y});
  }

  for (int i = 0, d = 0; i < Q; i++) {
    int t, x = -1, y = -1;
    t = queries[i][0];
    x = queries[i][1];
    y = queries[i][2];
    if (t == 1) {
      Add(x, y, 0, i, days[d + K] - 1);
    } else if (t == 2) {
      Add(x, i, 1, i, i);
    } else {
      d++;
    }
  }

  Dfs(1, 0, Q - 1);
  for (int i = 0; i < Q; i++) {
    if (ans[i] != -1) {
      cout << ans[i] << "\n";
    }
  }
  return 0;
}