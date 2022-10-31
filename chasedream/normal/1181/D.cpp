#include <bits/stdc++.h>
using namespace std;

#define int long long

void read(int &x) {
  scanf("%lld", &x); 
}

typedef long long ll;
const int N = 1000005;

struct city {
  int cnt, id;
  bool operator < (const city b) const {
    return cnt < b.cnt;
  }
} a[N];

struct que {
  int x, id;
  bool operator < (const que b) const {
    return x < b.x;
  }
} qq[N];

ll up[N], ans[N];
int n, m, q;

#define ls tr[rt].l
#define rs tr[rt].r
struct node {
  int l, r, val;
  int cnt, sz, rnd;
} tr[N];
int tot, rt;

void update(int rt) {
  tr[rt].sz = tr[ls].sz + tr[rs].sz + tr[rt].cnt;
}

void lturn(int &rt) {
  int tmp = rs;
  tr[rt].r = tr[tmp].l;
  tr[tmp].l = rt;
  tr[tmp].sz = tr[rt].sz;
  update(rt);
  rt = tmp;
}

void rturn(int &rt) {
  int tmp = ls;
  tr[rt].l = tr[tmp].r;
  tr[tmp].r = rt;
  tr[tmp].sz = tr[rt].sz;
  update(rt);
  rt = tmp;
}

void Insert(int &rt, int x) {
  if (!rt) {
    rt = ++tot;
    tr[rt].sz = tr[rt].cnt = 1;
    tr[rt].val = x, tr[rt].rnd = rand();
    return ;
  }
  tr[rt].sz++;
  
  if (tr[rt].val == x) tr[rt].cnt++;
  else if (tr[rt].val < x) {
    Insert(rs, x);
    if (tr[rs].rnd < tr[rt].rnd) lturn(rt);
  }
  else {
    Insert(ls, x);
    if (tr[ls].rnd < tr[rt].rnd) rturn(rt);
  }
}

void Delete(int &rt, int x) {
  if (!rt) return ;
  if (tr[rt].val == x) {
    if (tr[rt].cnt > 1) tr[rt].cnt--, tr[rt].sz--;
    else {
      if (ls * rs == 0) rt = ls + rs;
      else if (tr[ls].rnd < tr[rs].rnd)
        rturn(rt), Delete(rt, x);
      else
        lturn(rt), Delete(rt, x); 
    }
  }
  else if (tr[rt].val < x)
    tr[rt].sz--, Delete(rs, x);
  else
    tr[rt].sz--, Delete(ls, x);
}

int findnum(int rt, int x) {
  if (!rt) return -1;
  if (x <= tr[ls].sz) return findnum(ls, x);
  x -= tr[ls].sz;
  if (x <= tr[rt].cnt) return tr[rt].val;
  x -= tr[rt].cnt;
  return findnum(rs, x);
}

void doit() {
  int kind = 0;
  for (int _ = 1; _ <= q; _++) {
    while (kind < m && up[kind] < qq[_].x) {
      kind++;
      Insert(rt, a[kind].id);
    }
    ll dis = qq[_].x - up[kind - 1];
    dis = (dis - 1) % kind + 1;
    //printf("question %d: %lld\n", _, dis);
    ans[qq[_].id] = findnum(rt, dis);
    //printf("answer %d\n", ans[qq[_].id]);
  }
}

signed main() {
  read(n), read(m), read(q);
  for (int i = 1; i <= m; i++) a[i].id = i;
  for (int i = 1; i <= n; i++) {
    int x; scanf("%d", &x);
    a[x].cnt++;
  }
  /*
  for (int i = 1; i <= m; i++)
    printf("%d:%d\n", a[i].id, a[i].cnt);
  */
  sort(a + 1, a + m + 1);

  /*
  for (int i = 1; i <= m; i++)
    printf("%d:%d\n", a[i].id, a[i].cnt);
  */
  for (int i = 1; i <= m; i++) {
    up[i] = (ll)i * (a[i + 1].cnt - a[i].cnt);
    up[i] += up[i - 1];
    //printf("up[%d] = %d\n", i, up[i]);
  }
  
  for (int _ = 1; _ <= q; _++) {
    int x; scanf("%lld", &x);
    x -= n; qq[_] = (que){x, _};
  }
  sort(qq + 1, qq + q + 1);
  
  /*
  for (int _ = 1; _ <= q; _++)
    printf("question[%d] = %d\n", _, qq[_].x);
  */
  
  doit();
  
  for (int i = 1; i <= q; i++)
    printf("%lld\n", ans[i]);
}