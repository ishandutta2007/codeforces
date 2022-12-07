#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = 500010;
const int MaxM = MaxN << 3;

int n, m; 

struct edge {
  int u, v, l, r;
  edge(int u = 0, int v = 0, int l = 0, int r = 0) : u(u), v(v), l(l), r(r) {
  }
  bool operator < (const edge &b) const {
    return l != b.l ? l > b.l : r > b.r;
  }
};
vector<edge> ev[MaxN][2];
priority_queue<edge> q; int last[MaxN][2];

inline bool cmax(int &a, int b) {
  return a < b ? a = b, 1 : 0;
}

void ext(int a, int l, int r) {
  cmax(last[a][l & 1], r);
  for (auto e : ev[a][l & 1])
    e.l = l, q.push(e);
  ev[a][l & 1].clear();  
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b, l, r; scanf("%d%d%d%d", &a, &b, &l, &r); --r;
    int p = l ^ r, q_ = p ^ 1;
    q.push(edge(a, b, l, r - (p & 1)));
    q.push(edge(b, a, l, r - (p & 1)));
    q.push(edge(a, b, l + 1, r - (q_ & 1)));
    q.push(edge(b, a, l + 1, r - (q_ & 1)));
  }
  
  memset(last, -1, sizeof(last));
  
  last[1][0] = 0;
  while (!q.empty()) {
    edge c = q.top(); q.pop();
    if (c.l > c.r) continue;
    int o = c.l & 1; 
    if (c.l > last[c.u][o])
      ev[c.u][o].push_back(c);
    else
      if (c.v != n)
        ext(c.v, c.l + 1, c.r + 1);
      else {
        printf("%d\n", c.l + 1);
        return 0;
      }
  }
  if (n == 1)
    puts("0");
  else
    puts("-1");
  return 0;
}