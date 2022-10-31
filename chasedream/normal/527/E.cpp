#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rll RE ll
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i > 0; i = edge[i].nxt)
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

template <typename T1, typename T2>
void ckmax(T1 &x, T2 y) {
  if (x < y) x = y;
}

template <typename T1, typename T2>
void ckmin(T1 &x, T2 y) {
  if (x > y) x = y;
}

const int N = 500005;

struct Edge {
  int to, nxt, id;
} edge[N << 1];
int head[N], tot = 1;

void add(int u, int v, int id) {
  edge[++tot] = {v, head[u], id};
  head[u] = tot;
}

int in[N];
int n, m;

vector <pii> ans;
int rev;

int ind[N], vis[N];
void dfs(int u) {
  for (int i = head[u]; i; i = head[u]) {
    int v = edge[i].to, id = edge[i].id;
    head[u] = edge[i].nxt;
    if (!vis[id]) {
      vis[id] = 1;
      
      dfs(v);
      if (!rev) ans.push_back(mp(u, v));
      else ans.push_back(mp(v, u));
      rev ^= 1;
    }
  }
}

int main() {
  read(n, m);
  for (int i = 1; i <= m; i++) {
    int u, v; read(u, v);
    add(u, v, i); add(v, u, i);
    in[u]++, in[v]++;
  }

  int finds = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] & 1) {
      if (finds) {
        m++;
        add(finds, i, m); add(i, finds, m);
        finds = 0;
      }
      else finds = i;
    }
  }
  
  if (m & 1) {
    m++;
    add(1, 1, m); add(1, 1, m);
  }
  
  printf("%d\n", m);
  for (int i = 1; i <= n; i++) {
    if (!ind[i]) dfs(i); 
  }
  
  assert(ans.size() == m);
  for (auto v: ans) {
    cout << v.fi << ' ' << v.se << '\n';
  }
  return 0;
}