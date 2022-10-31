#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i; i = edge[i].nxt)
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second

template <typename T>
void read(T &x) {
  x = 0; char op = getchar(); int F = 1;
  while (!isdigit(op)) {
    if (op == '-') F *= -1; op = getchar();
  }
  while (isdigit(op)) {
    x = (x << 1) + (x << 3) + op - '0'; op = getchar();
  }
  x *= F;
}

template <typename T, typename ...Args>
void read(T &x, Args &...args) {
  read(x); read(args...); 
}

const int N = 1000005;

struct Edge {
  int to, nxt;
} edge[N << 1];
int head[N], tot;

void add(int u, int v) {
  edge[++tot] = {v, head[u]};
  head[u] = tot;
}

int Q[N][2];
int n, m, S;

int dfn[N], low[N], ff;
int vis[N], be[N];
stack <int> st;

void tarjan(int u) {
  dfn[u] = low[u] = ++ff;
  vis[u] = 1, st.push(u);
  Each(i) {
    rint v = edge[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } 
    else if (vis[v]) { 
      low[u] = min(low[u], dfn[v]);
    }
  }
  
  if (dfn[u] == low[u]) {
    int y;
    //printf("New block!\n");
    while (y = st.top()) {
      st.pop(); vis[y] = 0, be[y] = u;
      //printf("%d ", y);
      if (y == u) break;
    }
    //putchar('\n');
  }
}

int in[N];

int main() {
  read(n, m, S);
  for (rint i = 1; i <= m; i++) {
    int u, v; read(u, v);
    Q[i][0] = u, Q[i][1] = v;
    add(u, v);
  }
  
  for (rint i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  
  for (int i = 1; i <= m; i++) {
    int uF = be[Q[i][0]], vF = be[Q[i][1]];
    if (uF != vF) in[vF]++;
  }
  
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (be[i] == i) {
      ans += (in[i] == 0); 
      //if (in[i] == 0) printf("%d\n", i);
    }
  }
  
  if (in[be[S]] == 0) ans--;
  printf("%d\n", ans);
  return 0;
}