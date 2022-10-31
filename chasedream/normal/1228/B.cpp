#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define RE register
#define rint RE int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define req(i, l, r) for (rint i = l; i >= r; i--)
#define Each(i) for (rint i = head[u]; i > 0; i = edge[i].nxt)
#define pii pair <int, int>
#define pci pair <char, int>
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

int l, r;

bool check(int k) {
  int hsh[10] = {0};
  while (k > 0) {
    if (hsh[k % 10]) return 0;
    hsh[k % 10] = 1;
    k /= 10;
  } 
  return 1;
}

const int mod = 1e9 + 7;
int n, m;
int vis[1005][1005];

int main() {
  memset(vis, -1, sizeof(vis));
  read(n, m);
  for (int i = 1; i <= n; i++) {
    int x; read(x);
    for (int j = 1; j <= x; j++) {
      if (vis[i][j] == 0) {
        puts("0"); exit(0);
      }
      vis[i][j] = 1;
    }
    if (vis[i][x + 1] == 1) {
      puts("0"); exit(0);
    }
    vis[i][x + 1] = 0;
  }
  for (int j = 1; j <= m; j++) {
    int x; read(x);
    for (int i = 1; i <= x; i++) {
      if (vis[i][j] == 0) {
        puts("0"); exit(0);
      }
      vis[i][j] = 1;
    }
    if (vis[x + 1][j] == 1) {
      puts("0"); exit(0);
    }
    vis[x + 1][j] = 0;
  }
  
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j] == -1)
        ans *= 2, ans %= mod;
    } 
  }
  printf("%d\n", ans);
  return 0; 
}