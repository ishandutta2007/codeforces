#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 7;
const int INF = (int) 1e9 + 1;

struct T {
  int a;
  int b;
  int c;
  int d;
  int i;
};

bool cmp(T f, T s) {
  return f.a < s.a;
}

int n, dist[N], par[N], inv[N];
T x[N];

struct segTree {
  pair<int, int> tree[4 * N];
  void build(int v, int tl, int tr) {
    if (tl == tr)
      tree[v] = {x[tl].b, tl};
    else {
      int tm = (tl + tr) / 2;
      build(2 * v, tl, tm);
      build(2 * v + 1, tm + 1, tr);
      tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
  }
  pair<int, int> get(int v, int tl, int tr, int l, int r) {
    if (tr < l || r < tl)
      return {INF, INF};
    if (l <= tl && tr <= r)
      return tree[v];
    else {
      int tm = (tl + tr) / 2;
      return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
  }
  pair<int, int> get(int p) {
    return get(1, 1, n, 1, p);
  }
  void del(int v, int tl, int tr, int i) {
    if (tr < i || i < tl)
      return;
    if (tl == tr)
      tree[v].first = INF;
    else {
      int tm = (tl + tr) / 2;
      del(2 * v, tl, tm, i);
      del(2 * v + 1, tm + 1, tr, i);
      tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }
  }
  void del(int i) {
    del(1, 1, n, i);
  }
} t;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i].a >> x[i].b >> x[i].c >> x[i].d;
    x[i].i = i;
    dist[i] = -1;
  }
  sort(x + 1, x + n + 1, cmp);
  for (int i = 1; i <= n; i++)
    inv[x[i].i] = i;
  dist[0] = 0;
  queue<int> q;
  q.push(0);
  t.build(1, 1, n);
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    int l = 1, r = n, ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (x[mid].a <= x[i].c) {
        ans = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    while (1) {
      pair<int, int> it = t.get(ans);
      if (it.first > x[i].d)
        break;
      dist[it.second] = dist[i] + 1;
      par[it.second] = i;
      q.push(it.second);
      t.del(it.second);
    }
  }
  int node = inv[n];
  cout << dist[node] << "\n";
  if (dist[node] != -1) {
    vector<int> sol;
    while (dist[node] > 0) {
      sol.push_back(node);
      node = par[node];
    }
    reverse(sol.begin(), sol.end());
    for (auto &i : sol)
      cout << x[i].i << " ";
    cout << "\n";
    return 0;
  }

}