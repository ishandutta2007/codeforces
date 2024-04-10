%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 1000005;

#define ls u << 1
#define rs u << 1 | 1
 
vector <int> X;
int a[N], b[N], n;
int typ[N], x[N], y[N];

long long f[N << 2], s[N << 2];
int cnt[N << 2];

void pushup(int u) {
  f[u] = f[ls] + f[rs] + s[rs] * cnt[ls] - s[ls] * cnt[rs];
  s[u] = s[ls] + s[rs];
  cnt[u] = cnt[ls] + cnt[rs]; 
}

void add(int u, int l, int r, int x, int v, int vv) {
  if (l == r) {
    assert(l == x);
    cnt[u] += vv;
    s[u] += v;
    return ;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) add(ls, l, mid, x, v, vv);
  else add(rs, mid + 1, r, x, v, vv);
  pushup(u);
}

ll query(int u, int l, int r, int x, int y, ll &sum, int& tot) {
  if (l == x && r == y) {
    sum = s[u], tot = cnt[u];
    return f[u];
  }
  int mid = (l + r) >> 1, totL = 0, totR = 0;
  ll fL = 0, fR = 0, sumL = 0, sumR = 0;
  if (y <= mid) fL = query(ls, l, mid, x, y, sumL, totL);
  else if (x > mid) fR = query(rs, mid + 1, r, x, y, sumR, totR);
  else {
    fL = query(ls, l, mid, x, mid, sumL, totL);
    fR = query(rs, mid + 1, r, mid + 1, y, sumR, totR);
  }
  tot = totL + totR;
  sum = sumL + sumR;
  return fL + fR + sumR * totL - sumL * totR;
}

int getID(int x) {
  return lower_bound(X.begin(), X.end(), x) - X.begin();
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
    X.push_back(a[i]);
  }
  int q; scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &typ[i], &x[i], &y[i]);
    if (typ[i] == 1) {
      b[x[i]] += y[i];
      X.push_back(b[x[i]]);
    }
  }
  sort(X.begin(), X.end());
  int sz = unique(X.begin(), X.end()) - X.begin();
  X.resize(sz);
  
  for (int i = 1; i <= n; i++) {
    add(1, 0, sz - 1, getID(a[i]), a[i], 1);
  }
  for (int i = 1; i <= q; i++) {
    if (typ[i] == 1) {
      int &tmp = a[x[i]];
      add(1, 0, sz - 1, getID(tmp), -tmp, -1);
      tmp += y[i];
      add(1, 0, sz - 1, getID(tmp), tmp, 1);  
    }
    else {
      int down = lower_bound(X.begin(), X.end(), x[i]) - X.begin();
      int up = upper_bound(X.begin(), X.end(), y[i]) - X.begin();
      long long ans = 0LL, tmp;
      int tmp2;
      if (down < up) {
        up--;
        ans = query(1, 0, sz - 1, down, up, tmp, tmp2);
      }
      else ans = 0LL;
      printf("%lld\n", ans);
    }
  }
  return 0;
}