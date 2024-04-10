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

const int N = 500005;

namespace AC {
  int ch[N][26], fail[N];
  int End[N], AC_node;
  
  void Ins(char *str, int id) {
    int now = 0, len = strlen(str + 1);
    for (int i = 1; i <= len; i++) {
      int c = str[i] - 'a';
      if (!ch[now][c]) ch[now][c] = ++AC_node;
      now = ch[now][c];
    }
    End[id] = now;
  }
  
  void get_fail() {
    queue <int> q;
    for (int i = 0; i < 26; i++) {
      if (ch[0][i]) q.push(ch[0][i]);
    }
    
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int i = 0; i < 26; i++) {
        int &v = ch[u][i];
        if (v) {
          fail[v] = ch[fail[u]][i];
          q.push(v);
        }
        else v = ch[fail[u]][i];
      }
    }
  }
  
  vector <int> fson[N];
  void build() {
    for (int i = 1; i <= AC_node; i++) {
      fson[fail[i]].push_back(i); 
    }
    
    #ifdef debug
    for (int i = 1; i <= AC_node; i++) {
      if (fson[i].size() == 0) continue;
      printf("for fson %d\n", i);
      for (auto v: fson[i]) {
        printf("%d ", v);
      }
      putchar('\n');
    }
    #endif
  }
  
  int dfn[N], sz[N], ff;
  void dfs(int u) {
    //printf("in dfs %d -> %d\n", u, ff + 1); 
    dfn[u] = ++ff, sz[u] = 1;
    for (auto v: fson[u]) {
      dfs(v);
      sz[u] += sz[v];
    }
  }
}
using namespace AC;

struct ele {
  int to; char c;
};
vector <ele> son[N];
vector <int> que[N];

char str[N];
int ans[N], n, m;

#define ls (u << 1)
#define rs (u << 1 | 1)
int sum[N << 2];

void pushup(int u) {
  sum[u] = sum[ls] + sum[rs];
}

void upd(int u, int x, int y, int L, int R) {
  if (L == R) {
    sum[u] += y;
    return ;
  }
  int mid = (L + R) >> 1;
  if (x <= mid) upd(ls, x, y, L, mid);
  else upd(rs, x, y, mid + 1, R);
  pushup(u);
}

int query(int u, int l, int r, int L, int R) {
  if (l <= L && R <= r) return sum[u];
  int mid = (L + R) >> 1, ret = 0;
  if (l <= mid) ret += query(ls, l, r, L, mid);
  if (r > mid) ret += query(rs, l, r, mid + 1, R);
  return ret; 
}

void solve(int x, int now) {
  //printf("solve %d %d\n", x, now);

  upd(1, dfn[now], 1, 1, ff);
  for (auto i: que[x]) {
    ans[i] = query(1, dfn[End[i]], dfn[End[i]] + sz[End[i]] - 1, 1, ff);
  }
  for (auto v: son[x]) {
    solve(v.to, ch[now][v.c - 'a']);
  }
  upd(1, dfn[now], -1, 1, ff);
}

int main() {
  read(n);
  for (rint i = 1; i <= n; i++) {
    int opt; read(opt);
    int lst = 0; char c;
    if (opt == 1) scanf(" %c", &c);
    else scanf("%d %c", &lst, &c);
    son[lst].push_back({i, c});
  }
  
  read(m);
  for (rint i = 1; i <= m; i++) {
    int id; scanf("%d%s", &id, str + 1);
    Ins(str, i); que[id].push_back(i);
  }
  
  get_fail(); build();
  dfs(0);

  #ifdef debug
  for (int i = 1; i <= n; i++) {
    printf("%d\n", dfn[i]);
  }
  printf("%d\n", ff);
  #endif

  solve(0, 0);
  
  for (rint i = 1; i <= m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
} 

/*
10
1 a
2 1 b
2 1 b
2 3 a
1 a
2 2 b
2 5 a
1 b
1 a
2 6 b
10
7 a
1 b
7 b
10 ba
3 bb
3 ab
9 ab
4 b
6 a
6 bb
*/