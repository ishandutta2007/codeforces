// zzfy003
%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 5000005;
int n, q, cnt = 0;

#define ls (u << 1)
#define rs (u << 1 | 1)
#define sz(u) (R[u] - L[u] + 1)
int L[N], R[N];
int sum[N];

int gcd(int x, int y) {
  return y ? gcd(y, x % y) : x;
}

void pushup(int u) {
  sum[u] = gcd(sum[ls], sum[rs]);
}

void build(int u, int l, int r) {
  L[u] = l, R[u] = r;
  if (l == r) {
    scanf("%d", &sum[u]);
    return ;
  }
  
  int mid = (l + r) >> 1;
  build(ls, l, mid); build(rs, mid + 1, r);
  pushup(u);
}

void modify(int u, int x, int val) {
  if (L[u] == R[u]) {
    sum[u] = val;
    return ;
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (x <= mid) modify(ls, x, val);
  else modify(rs, x, val);
  pushup(u);
}

void query(int u, int ql, int qr, int d) {
  if (cnt > 1) return ;
  if (L[u] == R[u]) {
    cnt++;
    return ;
  }
  
  int mid = (L[u] + R[u]) >> 1;
  if (qr <= mid) {
    if (sum[ls] % d != 0) query(ls, ql, qr, d);
  }  
  else if (ql > mid) {
    if (sum[rs] % d != 0) query(rs, ql, qr, d);
  } 
  else {
    if (sum[ls] % d != 0) query(ls, ql, mid, d);
    if (sum[rs] % d != 0) query(rs, mid + 1, qr, d);
  }
}

int main() {
  scanf("%d", &n);
  build(1, 1, n);
  
  int q; scanf("%d", &q);
  while (q--) {
    int opt; scanf("%d", &opt);
    if (opt == 1) {
      int l, r, x; scanf("%d%d%d", &l, &r, &x);
      cnt = 0; query(1, l, r, x);
      puts(cnt > 1 ? "NO" : "YES");
    }
    else {
      int x, k; scanf("%d%d", &x, &k);
      modify(1, x, k);
    }
  }
  return 0;
}