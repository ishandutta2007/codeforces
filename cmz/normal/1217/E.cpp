#include <bits/stdc++.h>
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e9;
struct tree {
  int mn[N << 2][2];
  
  tree() {
    for(int i = 0; i < N * 4; ++i)
      mn[i][0] = mn[i][1] = inf;
  }
  
  void upd(int x, int w) {
    if(mn[x][0] > w) {
      mn[x][1] = mn[x][0], mn[x][0] = w;
    } else if(mn[x][1] > w) {
      mn[x][1] = w;
    }
  }
  
  void up(int x) {
    mn[x][0] = mn[x][1] = inf;
    for(int i = 0; i < 2; ++i)
      upd(x, mn[ls][i]), upd(x, mn[rs][i]);
  }
  
  void insert(int x, int l, int r, int L, int w) {
    if(l == r) {
      mn[x][0] = w; mn[x][1] = inf;
      return ;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) insert(ls, l, mid, L, w);
    else insert(rs, mid + 1, r, L, w);
    up(x);
  }
  
  void get(int x, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
     for(int i = 0; i < 2; ++i)
      upd(0, mn[x][i]);
     return ; 
    }
    int mid = (l + r) >> 1;
    if(L <= mid) get(ls, l, mid, L, R);
    if(R > mid) get(rs, mid + 1, r, L, R);
  }
} tr[12];
 
int nm[12], v[N];
int n, m;
 
void putin(int id, int x) {
  nm[0] = 0;
  for(; x; x /= 10) nm[++nm[0]] = x % 10;
  for(int i = 1; i <= nm[0]; ++i) {
    if(nm[i]) tr[i].insert(1, 1, n, id, v[id]);
  }
}
 
void erase(int id, int x) {
  nm[0] = 0;
  for(; x; x /= 10) nm[++nm[0]] = x % 10;
  for(int i = 1; i <= nm[0]; ++i) {
    if(nm[i]) tr[i].insert(1, 1, n, id, inf);
  }
}
 
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    scanf("%d", &v[i]);
    putin(i, v[i]);
  }
  for(int i = 1, x, y, z; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    if(x == 1) {
      erase(y, v[y]);
      v[y] = z;
      putin(y, v[y]);
    } else {
      int ans = 2e9;
      for(int i = 1; i <= 10; ++i) {
        tr[i].mn[0][0] = tr[i].mn[0][1] = inf;
        tr[i].get(1, 1, n, y, z);
        if(tr[i].mn[0][1] == inf) continue;
        ans = min(ans, tr[i].mn[0][0] + tr[i].mn[0][1]);
      }
      if(ans == 2e9) puts("-1");
      else printf("%d\n", ans);
    }
  }
  return 0;
}