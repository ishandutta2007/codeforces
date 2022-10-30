#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Node {
  ll s;
  int v;
  int t;
  int n;
  Node *ls, *rs;
  void pushUp() {
    s = ls->s + rs->s;
    v = rs->v;
  }
  void update(int t2) {
    s = 1LL * t2 * n;
    v = t2;
    t = t2;
  }
  void pushDown() {
    if (t != INT_MIN) {
      ls->update(t);
      rs->update(t);
      t = INT_MIN;
    }
  }
};

Node *build(int l, int r) {
  Node *cur = new Node{0, 0, INT_MIN, r - l + 1, nullptr, nullptr};
  if (l != r) {
    int mid = (l + r) / 2;
    cur->ls = build(l, mid);
    cur->rs = build(mid + 1, r);
    cur->pushUp();
  }
  return cur;
}

void cover(Node *cur, int l, int r, int a, int b, int v) {
  if (a <= l && b >= r) {
    cur->update(v);
  } else {
    cur->pushDown();
    int mid = (l + r) / 2;
    if (a <= mid) {
      cover(cur->ls, l, mid, a, b, v);
    }
    if (b > mid) {
      cover(cur->rs, mid + 1, r, a, b, v);
    }
    cur->pushUp();
  }
}

ll query(Node *cur, int l, int r, int a, int b) {
  if (a > b) return 0;
  if (a <= l && b >= r) {
    return cur->s;
  }
  cur->pushDown();
  int mid = (l + r) / 2;
  ll ret = 0;
  if (a <= mid) {
    ret += query(cur->ls, l, mid, a, b);
  }
  if (b > mid) {
    ret += query(cur->rs, mid + 1, r, a, b);
  }
  return ret;
}

int smallIndex(Node *cur, int l, int r, int v) {
  if (l == r) {
    return cur->v <= v ? l : l + 1;
  }
  cur->pushDown();
  int mid = (l + r) / 2;
  int ret;
  if (cur->ls->v <= v) {
    ret = smallIndex(cur->ls, l, mid, v);
  } else {
    ret = smallIndex(cur->rs, mid + 1, r, v);
  }
  return ret;
}

int bigIndex(Node *cur, int l, int r, ll v) {
  if (l == r) {
    return cur->s <= v ? l : l - 1;
  }
  cur->pushDown();
  int mid = (l + r) / 2;
  int ret;
  if (cur->ls->s <= v) {
    ret = bigIndex(cur->rs, mid + 1, r, v - cur->ls->s);
  } else {
    ret = bigIndex(cur->ls, l, mid, v);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  Node *root = build(1, n);
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cover(root, 1, n, i, i, a[i]);
  }
  auto check = [&]() -> void {
    int t = 10000;
    while (t--) {
      int l = rand() % n + 1;
      int r = rand() % n + 1;
      if (l > r) {
        swap(l, r);
      }
      ll sum = 0;
      for (int i = l; i <= r; i++) {
        sum += a[i];
      }
      assert(sum == query(root, 1, n, l, r));
    }
  };
  check();
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      int p = smallIndex(root, 1, n, y);
      if (p <= x) {
        cover(root, 1, n, p, x, y);
      }
    } else {
      int p = x;
      int ans = 0;
      // cout << "---" << p << "---" << endl;
      while (p <= n) {
        int p2 = smallIndex(root, 1, n, y);
        if (p2 > n) {
          break;
        }
        if (p2 > p) {
          p = p2;
          // cout << "---" << p2 << "---" << endl;
        }

        ll b = query(root, 1, n, 1, p - 1);
        p2 = bigIndex(root, 1, n, b + y);

        // cout << "!!!" << p2 << "!!!" << endl;

        assert(p2 >= p);
        y -= query(root, 1, n, p, p2);
        assert(y >= 0);
        ans += p2 - p + 1;
        p = p2 + 1;
      }
      cout << ans << "\n";
    }
  }
  return 0;
}