#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

char a[514][514];
int n, m;
int ID[514][514];
int RID[20005];
int idt[20005];
int g[20005];

int FIND(int x) { return g[x]==x? x: (g[x]=FIND(g[x])); }
void UNION(int x, int y) {
  x = FIND(x); y = FIND(y);
  g[x] = y;
}
int edge(int x, int y) {
  if (FIND(x) == FIND(y)) return 1;
  UNION(x, y);
  return 0;
}

LL P[2][514][514];
int MOD = 1e9+7;
int nid=0, Pid[2]={};

void bridge(int x, int y) {
  x = FIND(x); y = FIND(y);
  if (x == y) return;
  P[idt[x]][RID[x]][RID[x]]++;
  P[idt[x]][RID[x]][RID[y]]--;
  P[idt[x]][RID[y]][RID[x]]--;
  P[idt[x]][RID[y]][RID[y]]++;
}

LL inv(LL x, LL y, LL p, LL q, LL r, LL s) {
  if (y==0) return (p%MOD+MOD)%MOD;
  return inv(y, x%y, r, s, p-r*(x/y), q-s*(x/y));
}

LL det(LL F[514][514], int D) {
  LL ans = 1;
  for (int i = 0; i < D; i++) {
    int r = i;
    while(r < D && F[r][i] == 0) ++r;
    if (r >= D) return 0;
    if (r != i) ans = ans * (MOD-1) % MOD;
    for(int j=i;j<D;j++) swap(F[r][j], F[i][j]);
    ans = ans * F[i][i] % MOD;

    LL t = inv(F[i][i], MOD, 1, 0, 0, 1);
    for(int j=i;j<D;j++) F[i][j] = (F[i][j] * t) % MOD;
    for(int r=i+1;r<D;r++) if(F[r][i] != 0) {
      LL s = F[r][i];
      for(int j=i;j<D;j++) {
        F[r][j] = (F[r][j] - s * F[i][j]) % MOD;
        if (F[r][j] < 0) F[r][j] += MOD;
      }
    }
  }
  return ans;
}

int main(void) {
  scanf("%d%d%d", &n, &m, &MOD);
  assert(1<=n && n<=100);
  assert(1<=m && m<=100);
  for(int i=0;i<n;i++) scanf("%s", a[i]);
  for(int i=0;i<n;i++) assert(strlen(a[i]) == m);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) assert(a[i][j]=='/' || a[i][j]=='\\' || a[i][j]=='*');

  for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) {
    ID[i][j] = ++nid;
    g[nid] = nid;
    idt[nid] = (i%2)^(j%2);
  }
  int fail = 0;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
    if (a[i][j] == '/') {
      fail |= edge(ID[i+1][j], ID[i][j+1]);
    } else if (a[i][j] == '\\') {
      fail |= edge(ID[i][j], ID[i+1][j+1]);
    }
  }
  if (fail) { puts("0"); return 0; }
  for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) if(FIND(ID[i][j]) == ID[i][j]) {
    RID[ID[i][j]] = Pid[idt[ID[i][j]]]++;
  }

  int cnt = 0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if (a[i][j]=='*') {
        bridge(ID[i][j], ID[i+1][j+1]);
        bridge(ID[i+1][j], ID[i][j+1]);
        ++cnt;
      }
    }
  }
  assert(cnt <= 200);
  //fprintf(stderr, "* count = %d; D=%d; %d\n", cnt, Pid[0], Pid[1]);
  for(int z=0;z<2;z++)
  for(int i=0;i<Pid[z];i++) for(int j=0;j<Pid[z];j++) P[z][i][j] = (P[z][i][j] + MOD) % MOD;

  LL ans = det(P[0], Pid[0]-1) + det(P[1], Pid[1]-1);
  printf("%d\n", (int)(ans % MOD));
  return 0;
}