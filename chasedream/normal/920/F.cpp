// zzfy003
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 4000005;

#define ls (u << 1)
#define rs (u << 1 | 1)
#define sz(u) (R[u] - L[u] + 1)
int a[N], L[N], R[N];
ll sum[N];

int d[N], n, m;
void pre(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j += i)
      d[j]++;
  }
  d[1] = 2;
}

void pushup(int u) {
  sum[u] = sum[ls] + sum[rs];
}

void build(int u, int l, int r) {
  L[u] = l, R[u] = r;
  if (l == r) {
    sum[u] = a[l];
    return ;
  }
  
  int mid = (l + r) >> 1;
  build(ls, l, mid); build(rs, mid + 1, r);
  pushup(u);
}

void modify(int u, int l, int r) {
  if (sum[u] == 2 * sz(u)) return ;
  if (L[u] == R[u]) {
    sum[u] = d[sum[u]];
    return ;
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (r <= mid) modify(ls, l, r);
  else if (l > mid) modify(rs, l, r);
  else {
    modify(ls, l, mid); modify(rs, mid + 1, r);
  }
  pushup(u); 
}

ll query(int u, int l, int r) {
  if (L[u] == l && R[u] == r) {
    return sum[u];
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (r <= mid) return query(ls, l, r);
  else if (l > mid) return query(rs, l, r);
  else return query(ls, l, mid) + query(rs, mid + 1, r);
}

int cnt[N];

int main() {
  pre(1e6);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[i] = cnt[i - 1] + (a[i] == 1);
    if (a[i] == 1) a[i] = 2;
  }
  build(1, 1, n);
  
  while (m--) {
    int opt; scanf("%d", &opt);
    int l, r; scanf("%d%d", &l, &r);
    if (opt == 1) { // update [l, r] to d([l..r])
      modify(1, l, r);
    }
    else { // query [l, r]
      printf("%lld\n", query(1, l, r) - (cnt[r] - cnt[l - 1]));
    }
  }
  return 0;
}