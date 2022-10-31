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
#define Each(i) for (rint i = head[u]; i != -1; i = edge[i].nxt)
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

#define int long long
const int N = 200005;

int ru[N];
vector <int> adj[N];
inline void add(int u, int v) {
  adj[u].push_back(v);
  ru[v]++; 
}

int col[N][5];
int n;

inline bool check() {
  for (int i = 1; i <= n; i++) {
    if (ru[i] > 2) {
      return 0;
    }
  }
  
  return 1;
}

ll dfn[N], ff;
void dfs(int u, int fa) {
  dfn[++ff] = u;
  for (auto v: adj[u]) {
    if (v == fa) continue;
    dfs(v, u);
  }
}

int c[3], ANS[N], ans = 1e18;
int _ans[3];

signed main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);

  read(n);
  for (int j = 0; j < 3; j++) {
    for (int i = 1; i <= n; i++) {
      read(col[i][(j + 1) % 3]);
    } 
  }
  
  for (int i = 1; i < n; i++) {
    int u, v; read(u, v);
    add(u, v); add(v, u);
  }
  
  if (!check()) {
    puts("-1"); exit(0);
  }
  int root = 0;
  for (int i = 1; i <= n; i++) {
    if (ru[i] == 1) {
      root = i;
      break;
    }
  }
  //cerr << root << '\n';
  dfs(root, -1);
  
  //cerr << "ok3\n";
  #ifdef debug
  for (int i = 1; i <= n; i++) {
    printf("%d ", dfn[i]);
  }
  puts("");
  #endif
  
  for (rint l1 = 0; l1 < 3; l1++) {
    for (rint l2 = 0; l2 < 3; l2++) {
      for (rint l3 = 0; l3 < 3; l3++) {
        if (l1 == l2 || l2 == l3 || l1 == l3) continue;
        c[0] = l1, c[1] = l2, c[2] = l3;
        //vector <int> _ret; _ret.push_back(l1); _ret.push_back(l2); _ret.push_back(l3);
        ll ret = 0;
        for (int i = 1; i <= n; i++) {
          ret += col[dfn[i]][c[(i - 1) % 3]];
        }
        if (ret < ans) {
          ans = ret;
          memcpy(_ans, c, sizeof(c));
        }
      }
    }
  }
  
  #ifdef debug
  for (auto v: _ans)
    printf("%d ", v);
  putchar('\n'); putchar('\n');
  #endif
  /*
  for (int i = 0; i < 3; i++) {
    cerr << _ans[i] << ' ';
  }
  */
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    ANS[dfn[i]] = _ans[(i - 1) % 3];
  }
  for (int i = 1; i <= n; i++) {
    if (!ANS[i]) printf("3 ");
    else printf("%lld ", ANS[i]);
  }
  putchar('\n');
  return 0;
}