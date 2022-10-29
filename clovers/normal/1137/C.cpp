#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long li;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;

inline int Add(int x) { return x >= mod ? x - mod : x; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline int Mul(int x, int y) { return (li)x * y % mod; }
inline int Mul(int x, int y, int z) { return Mul(Mul(x, y), z); }

inline void Max(int &x, int y) { if (y > x) x = y; }

int Pow(int x, int y) {
  int z = 1;
  for (; y; y >>= 1) {
    if (y & 1) z = Mul(z, x);
    x = Mul(x, x);
  }
  return z;
}

const int maxn = 1e5, maxd = 50;
const int maxnv = 5000000, maxne = maxnv;

int n, d, m, nv;
pii g[maxne];
int ne;
int head[maxnv + 1];
int stk[maxnv], top;
int cntscc, sccid[maxnv];
int dfn[maxnv], clk;

char valid[maxn][maxd + 1];

vector<int> g2[maxnv];
int self[maxnv], dp[maxnv];
bool vis[maxnv];

inline int ID(int u, int i) {
  return u * d + i;
}

int Dfs(int u) {
  int low = dfn[u] = clk++;
  stk[top++] = u;
  for (int i = head[u]; i < head[u + 1]; ++i) {
    int v = g[i].second;
    if (dfn[v] == -1) {
      low = min(low, Dfs(v));
    } else if (sccid[v] == -1) {
      low = min(low, dfn[v]);
    }
  }
  if (low == dfn[u]) {
    int v;
    do {
      v = stk[--top];
      sccid[v] = cntscc;
    } while (v != u);
    ++cntscc;
  }
  return low;
}

void GetScc(void) {
  clk = top = cntscc = 0;
  for (int x = 0; x < nv; ++x) sccid[x] = dfn[x] = -1;
  for (int x = 0; x < nv; ++x) {
    if (dfn[x] == -1) Dfs(x);
  }
  for (int x = 0; x < nv; ++x) {
    for (int i = head[x]; i < head[x + 1]; ++i) {
      int y = g[i].second;
      if (sccid[x] != sccid[y]) g2[sccid[x]].push_back(sccid[y]);
    }
  }
}

int main(void) {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u; --v;
    for (int j = 0; j < d; ++j) {
      g[ne++] = {ID(u, j), ID(v, (j + 1) % d)};
    }
  }

  sort(g, g + ne);
  int cur = 0;
  for (int i = 0; i < ne; ++i) {
    while (cur <= g[i].first) {
      head[cur++] = i;
    }
  }
  nv = n * d;
  while (cur <= nv) {
    head[cur++] = ne;
  }

  // for (int i = 0; i < ne; ++i) {
  //   printf("(%d %d)\n", g[i].first, g[i].second);
  // }

  // for (int i = 0; i < nv; ++i) {
  //   printf("out[%d]\n", i);
  //   for (int j = head[i]; j < head[i + 1]; ++j) {
  //     printf("(%d, %d)\n", g[j].first, g[j].second);
  //   }
  // }
  
  // printf("ne = %d\n", ne);
  // for (int i = 0; i <= nv; ++i) printf("head[%d] = %d\n", i, head[i]);
  // for (int i = 0; i < ne; ++i) printf("(%d %d)\n", g[i].first, g[i].second);

  for (int i = 0; i < n; ++i) scanf("%s", valid[i]);
  GetScc();
  int n2 = cntscc;
  // printf("cntscc = %d\n", cntscc);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      if (valid[i][j] == '0') continue;
      int x = sccid[ID(i, j)];
      if (vis[x]) continue;
      ++self[x];
      vis[x] = true;
    }
    for (int j = 0; j < d; ++j) {
      if (valid[i][j] == '0') continue;
      int x = sccid[ID(i, j)];
      vis[x] = false;
    }
  }
  for (int i = 0; i < n2; ++i) {
    for (int j : g2[i]) {
      Max(dp[i], dp[j]);
    }
    dp[i] += self[i];
  }
  printf("%d\n", dp[sccid[0]]);
  return 0;
}