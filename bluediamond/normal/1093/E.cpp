#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;

int n, q, devine[N], a[N], b[N];
vector<int> question[N];
set<int> points[N];
vector<int> e[N];
vector<int> tree[N];

void add_need(int i, int x) {
  while (i <= n) {
    points[i].insert(x);
    i += i & (-i);
  }
}

void add(int i, int x, int sgn) {
  int init = 5;
  while (i <= n) {
    int pos = lower_bound(e[i].begin(), e[i].end(), x + 1) - e[i].begin();
    while (pos <= (int) e[i].size()) {
      tree[i][pos] += sgn;
      pos += pos & (-pos);
    }
    i += i & (-i);
  }
}

int get(int i, int x) {
  int sol = 0;
  while (i >= 1) {
    int pos = lower_bound(e[i].begin(), e[i].end(), x + 1) - e[i].begin();
    while (pos) {
      sol += tree[i][pos];
      pos -= pos & (-pos);
    }
    i -= i & (-i);
  }
  return sol;
}

int cnt(int l, int r, int x) {
  int sol = get(r, x) - get(l - 1, x);
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    devine[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i] = devine[a[i]];
    add_need(i, a[i]);
  }
  for (int i = 1; i <= q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int lo, hi, l, r;
      cin >> lo >> hi >> l >> r;
      question[i] = {lo, hi, l, r};
    } else {
      int p1, p2;
      cin >> p1 >> p2;
      question[i] = {p1, p2};
      add_need(p1, a[p1]);
      add_need(p2, a[p2]);
      swap(a[p1], a[p2]);
      add_need(p1, a[p1]);
      add_need(p2, a[p2]);
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    for (auto &x : points[i]) {
      e[i].push_back(x);
    }
    tree[i].resize((int) e[i].size() + 1, 0);
  }
  for (int i = 1; i <= n; i++) {
    add(i, a[i], +1);
  }
  for (int i = 1; i <= q; i++) {
    if ((int) question[i].size() == 4) {
      int lo, hi, l, r;
      lo = question[i][0];
      hi = question[i][1];
      l = question[i][2];
      r = question[i][3];
      cout << cnt(l, r, hi) - cnt(l, r, lo - 1) << "\n";
    } else {
      int p1, p2;
      p1 = question[i][0];
      p2 = question[i][1];
      add(p1, a[p1], -1);
      add(p2, a[p2], -1);
      swap(a[p1], a[p2]);
      add(p1, a[p1], +1);
      add(p2, a[p2], +1);
    }
  }
}