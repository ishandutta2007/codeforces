#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;

struct SegTree {
  struct Node {
    int max1 = 2e9, max2 = -1;
    int cnt = 0;
    int lazy = 2e9;
    long long dp = 0;
  };
  int n;
  vector<Node> T;
  
  SegTree(int n) : n(n), T(4 * n) {}

  void push(int node, int b, int e) {
    int lazy = T[node].lazy;
    if (lazy < T[node].max1) {
      assert(lazy > T[node].max2);
      int delta = lazy - T[node].max1;
      T[node].dp += 1LL * delta * T[node].cnt;
      T[node].max1 = lazy;

      if (b != e) {
        T[node * 2].lazy = min(T[node * 2].lazy, lazy);
        T[node * 2 + 1].lazy = min(T[node * 2 + 1].lazy, lazy);
      }
    }
    T[node].lazy = 2e9;
  }

  void pull(int node, int b, int e) {
    assert(b < e);
    int l = node * 2, r = node * 2 + 1; int m = (b + e) / 2;
    push(l, b, m); push(r, m + 1, e);

    int all[] = {T[l].max1, T[l].max2, T[r].max1, T[r].max2};
    sort(all, all + 4);
    int sz = unique(all, all + 4) - all;
    T[node].max1 = all[sz - 1];
    T[node].max2 = all[sz - 2];
    assert(T[node].max1 == max(T[l].max1, T[r].max1));
    assert(T[node].max2 < T[node].max1);
    T[node].cnt = 0;
    if (T[l].max1 == T[node].max1)
      T[node].cnt += T[l].cnt;
    if (T[r].max1 == T[node].max1)
      T[node].cnt += T[r].cnt;
    T[node].dp = T[l].dp + T[r].dp;
  }


  void update(int node, int b, int e, int l, int r, int x) {
    push(node, b, e);
    l = max(l, b); r = min(r, e);
    if (l > r || x >= T[node].max1) return;
    // if (b == e) {
    if (b == l && e == r && x > T[node].max2) {
      T[node].lazy = x;
      push(node, b, e);
      return;
    }
    assert(b != e);
    int m = (b + e) / 2;
    update(node * 2, b, m, l, r, x);
    update(node * 2 + 1, m + 1, e, l, r, x);
    pull(node, b, e);
  }

  void Update(int l, int r, int x) {
    update(1, 0, n - 1, l, r, x);
  }

  void activate(int node, int b, int e, int pos) {
    push(node, b, e);
    if (b == e) {
      assert(b == pos);
      assert(T[node].cnt == 0);
      T[node].cnt = 1;
      T[node].dp = T[node].max1;
      return;
    }
    int m = (b + e) / 2;
    if (pos <= m) activate(node * 2, b, m, pos);
    else activate(node * 2 + 1, m + 1, e, pos);
    pull(node, b, e);
  }

  void Activate(int pos) {
    activate(1, 0, n - 1, pos);
  }

  long long query(int node, int b, int e, int l, int r) {
    push(node, b, e);
    l = max(l, b); r = min(r, e);
    if (l > r) return 0;
    if (b == l && e == r) return T[node].dp;
    int m = (b + e) / 2;
    return query(node * 2, b, m, l, r) + 
      query(node * 2 + 1, m + 1, e, l, r);
  }

  long long Query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  set<int> vals[4];
  for (int i = 0; i < MAX; ++i)
    vals[0].insert(i);

  SegTree lo(MAX), hi(MAX);
  int q; cin >> q;
  while (q--) {
    int typ; cin >> typ;
    if (typ == 1) {
      int l, r, k; cin >> l >> r >> k; --l; r -= 2;
      if (k > 0) {
        hi.Update(l, r, k);
        for (int m : {0, 2}) {
          auto it = vals[m].lower_bound(l);
          while (it != vals[m].end() && *it <= r) {
            vals[m | 1].insert(*it);
            it = vals[m].erase(it);
          }
        }
      } else {
        lo.Update(l, r, -k);
        for (int m : {0, 1}) {
          auto it = vals[m].lower_bound(l);
          while (it != vals[m].end() && *it <= r) {
            vals[m | 2].insert(*it);
            it = vals[m].erase(it);
          }
        }
      }
      for (auto x : vals[3]) {
        lo.Activate(x);
        hi.Activate(x);
      }
      vals[3].clear();
    } else {
      int l, r; cin >> l >> r; --l; r -= 2;
      cout << lo.Query(l, r) + hi.Query(l, r) << '\n';
    }
  }
  return 0;
}