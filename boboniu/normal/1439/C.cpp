#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 223456

struct Tnode {
  array<i64, 3> info;
  int size;
  int valset;
} node[4 * maxN];
int a[maxN], n, q;
array<i64, 3> operator+(array<i64, 3> &a, array<i64, 3> &b) {
  return {a[0] + b[0], max(a[1], b[1]), min(a[2], b[2])};
}

void setval(int id, int val) {
  node[id].valset = val;
  node[id].info = {(i64)node[id].size * val, val, val};
}
void clear(int id) {
  if (node[id].valset != -1) {
    setval(id * 2, node[id].valset);
    setval(id * 2 + 1, node[id].valset);
    node[id].valset = -1;
  }
}

void build(int id, int l, int r) {
  node[id].valset = -1;
  node[id].size = r - l + 1;
  if (l == r) {
    node[id].info = {a[l], a[l], a[l]};
  } else {
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    node[id].info = node[id * 2].info + node[id * 2 + 1].info;
  }
}

void rangeset(int id, int l, int r, int rl, int rr, int v) {
  if (l == rl && r == rr) {
    if (node[id].info[2] >= v)
      return;
    if (node[id].info[1] <= v) {
      // printf("setval %d %d %d\n", l, r, v);
      setval(id, v);
      return;
    }
    clear(id);
    int m = (l + r) / 2;
    rangeset(id * 2, l, m, l, m, v);
    rangeset(id * 2 + 1, m + 1, r, m + 1, r, v);
    node[id].info = node[id * 2].info + node[id * 2 + 1].info;
  } else {
    clear(id);
    int m = (l + r) / 2;
    if (rr <= m)
      rangeset(id * 2, l, m, rl, rr, v);
    else if (rl > m)
      rangeset(id * 2 + 1, m + 1, r, rl, rr, v);
    else {
      rangeset(id * 2, l, m, rl, m, v);
      rangeset(id * 2 + 1, m + 1, r, m + 1, rr, v);
    }
    node[id].info = node[id * 2].info + node[id * 2 + 1].info;
  }
}

int getnext(int id, int l, int r, int rl, int rr, int v) {
  if (l == rl && r == rr) {
    if (node[id].info[1] <= v)
      return l;
    if (node[id].info[2] > v)
      return n + 1;
    clear(id);
    int m = (l + r) / 2;
    return min(getnext(id * 2, l, m, l, m, v),
               getnext(id * 2 + 1, m + 1, r, m + 1, r, v));
  } else {
    clear(id);
    int m = (l + r) / 2;
    if (rr <= m)
      return getnext(id * 2, l, m, rl, rr, v);
    else if (rl > m)
      return getnext(id * 2 + 1, m + 1, r, rl, rr, v);
    else {
      return min(getnext(id * 2, l, m, rl, m, v),
                 getnext(id * 2 + 1, m + 1, r, m + 1, rr, v));
    }
  }
}
bool isful;
int cnt;
void geteat(int id, int l, int r, int rl, int rr, int &v) {
  if (!isful) {
    return;
  }
  if (l == rl && r == rr) {
    if (node[id].info[0] <= v) {
      v -= node[id].info[0];
      cnt += node[id].size;
      return;
    }
    if (l == r) {
      isful = false;
      return;
    }
    clear(id);
    int m = (l + r) / 2;
    geteat(id * 2, l, m, l, m, v);
    geteat(id * 2 + 1, m + 1, r, m + 1, r, v);
  } else {
    clear(id);
    int m = (l + r) / 2;
    if (rr <= m)
      geteat(id * 2, l, m, rl, rr, v);
    else if (rl > m)
      geteat(id * 2 + 1, m + 1, r, rl, rr, v);
    else {
      geteat(id * 2, l, m, rl, m, v);
      geteat(id * 2 + 1, m + 1, r, m + 1, rr, v);
    }
  }
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  build(1, 1, n);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      rangeset(1, 1, n, 1, x, y);
    } else {
      int pos = x, c = 0;
      while (pos <= n) {
        pos = getnext(1, 1, n, pos, n, y);
        if (pos == n + 1)
          break;
        isful = true;
        cnt = 0;
        geteat(1, 1, n, pos, n, y);
        c += cnt;
        pos += cnt;
      }
      printf("%d\n", c);
    }
  }
}