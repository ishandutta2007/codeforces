#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct item {
  item() {
    // memset(t, -1, sizeof(t));
  }
  int t[62];
};

int arr[100005];
item tree[400005];

item merge(const item& a, const item& b) {
  item ret;
  for (int i = 0; i < 60; ++i) {
    ret.t[i] = a.t[i] + b.t[(i + a.t[i]) % 60];
  }
  return ret;
}

void build(int i, int l, int r) {
  if (l == r) {
    for (int j = 0; j < 60; ++j) {
      tree[i].t[j] = 1 + (j % arr[l] == 0);
    }
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
  // if (l == 5 && r == 7) {
  //   cout << tree[2 * i].t[5] << endl;
  //   for (int j = 0; j < 10; ++j)
  //     cout << tree[i].t[j] << " ";
  //   cout << endl;
  // }
}

item find(int i, int l, int r, int L, int R) {
  if (l == L && r == R) {
    // cout << l << "  " << r << " " << tree[i].t[5] << endl;
    return tree[i];
  }
  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R);
  if (L > m)  return find(2 * i + 1, m + 1, r, L, R);
  return merge(find(2 * i, l, m, L, m), find(2 * i + 1, m + 1, r, m + 1, R));
}

void update(int i, int l, int r, int pos, int val) {
  if (l == r) {
    arr[l] = val;
    for (int j = 0; j < 60; ++j) {
      tree[i].t[j] = 1 + (j % arr[l] == 0);
    }
    return;
  }
  int m = (l + r) >> 1;
  if (pos <= m) update(2 * i, l, m, pos, val);
  else update(2 * i + 1, m + 1, r, pos, val);
  tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
}

int main() {
  // cout << sizeof(tree) / 1024.0 / 1024 << endl;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  // arr[9] = 6; arr[2] = 4;
  build(1, 0, n - 1);
  int q;
  scanf("%d\n", &q);
  while (q--) {
    char c; int x, y;
    scanf("%c %d %d\n", &c, &x, &y);
    if (c == 'C') {
      --x;
      update(1, 0, n - 1, x, y);
    } else {
      --x; --y;
      printf("%d\n", find(1, 0, n - 1, x, y - 1).t[0]);
    }
  }
  return 0;
}