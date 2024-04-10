#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int ma[N << 2], add[N << 2], a[N << 2], n;

void build(int id = 1, int l = 0, int r = n) {
  add[id] = 0;
  if (r-l < 2) {
    ma[id ]= a[l];
    return;
  }
  int mid = (l + r) / 2, il = id << 1, ir = il | 1;
  build(il, l, mid);
  build(ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

void shilft(int id) {
  if (add[id]) {
    int il = id << 1, ir = il | 1;
    ma[il] += add[id];
    add[il] += add[id];
    ma[ir] += add[id];
    add[ir] += add[id];
    add[id] = 0;
  }
}

void update(int x, int y, int val, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return;
  if (x <= l && r <= y) {
    add[id] += val;
    ma[id] += val;
    return;
  }
  shilft(id);
  int mid = (l + r) / 2, il = id << 1, ir = il | 1;
  update(x, y, val, il, l, mid);
  update(x, y, val, ir, mid, r);
  ma[id] = max(ma[il], ma[ir]);
}

int get(int x, int y, int id = 1, int l = 0, int r = n) {
  if (x >= r || l >= y) return 0;
  if (x <= l && r <= y) {
    return ma[id];
  }
  shilft(id);
  int mid = (l + r) / 2, il = id << 1, ir = il | 1;
  return max(get(x, y, il, l, mid), get(x, y, ir, mid, r));
}

int x[N], bef[N], last[N];

int main() {
  int k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d", x+i);
  for (int i = 1; i <= n; i++) {
    bef[i] = last[x[i]];
    last[x[i]] = i;
  }
  n++;
  memset(a, 0, sizeof a);
  for (int i = 0; i < k; i++) {
    build();
    for (int j = 1; j < n; j++) {
      update(bef[j], j, 1);
      a[j] = get(0, j);
    }
  }
  printf("%d\n", a[n-1]);
  return 0;
}