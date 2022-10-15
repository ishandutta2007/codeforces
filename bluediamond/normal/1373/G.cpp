#include <bits/stdc++.h>

using namespace std;

const int N = (int) 6e5 + 7;
const int INF = (int) 1e9 + 7;
int n;
int kpos;
int m;
int dim;
int tree[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr) {
  if (lazy[v]) {
    tree[v] += lazy[v];
    if (tl < tr) {
      lazy[2 * v] += lazy[v];
      lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
  }
}

void add(int v, int tl, int tr, int l, int r, int x) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return;
  }
  if (l <= tl && tr <= r) {
    lazy[v] += x;
    push(v, tl, tr);
    return;
  }
  int tm = (tl + tr) / 2;
  add(2 * v, tl, tm, l, r, x);
  add(2 * v + 1, tm + 1, tr, l, r, x);
  tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r) {
  push(v, tl, tr);
  if (tr < l || r < tl) {
    return -INF;
  }
  if (l <= tl && tr <= r) {
    return tree[v];
  }
  int tm = (tl + tr) / 2;
  return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r) {
  return get(1, 1, dim, l, r);
}

void add(int l, int r, int x) {
  add(1, 1, dim, l, r, x);
}


signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> kpos >> m;
  dim = max(n, m) * 3 + 3;

  for (int i = 1; i <= dim; i++) {
    add(i, i, i);
  }

  set<pair<int, int>> active;
  for (int iter = 1; iter <= m; iter++) {
    pair<int, int> it;
    cin >> it.first >> it.second;

    if (active.count(it)) {
      int x = it.first, y = it.second;
      int dist = y + abs(x - kpos);
      add(1, dist, -1);
      assert(1 <= dist && dist <= dim);
      active.erase(it);
    } else {
      int x = it.first, y = it.second;
      int dist = y + abs(x - kpos);
      add(1, dist, +1);
      assert(1 <= dist && dist <= dim);
      active.insert(it);
    }
    int low = 1, high = dim, cnt = 0;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (get(1, mid) > mid) {
        cnt = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    cout << max(0, cnt - n) << "\n";
  }
}