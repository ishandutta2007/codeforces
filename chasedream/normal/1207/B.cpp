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

const int N = 55;
int a[N][N], vis[N][N];
int n, m;

vector <pii> ans;

int ok(int x, int y) {
  for (int i = x; i <= x + 1; i++) {
    for (int j = y; j <= y + 1; j++) {
      if (a[i][j] == 0)
        return 0;
    }
  }
  return 1;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (ok(i, j)) {
        ans.push_back(mp(i, j));
        vis[i][j] = vis[i + 1][j] = vis[i][j + 1] = vis[i + 1][j + 1] = 1;
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] ^ vis[i][j]) {
        puts("-1"); exit(0);
      }
    }
  }
  
  printf("%d\n", (int)ans.size());
  for (auto v: ans)
    printf("%d %d\n", v.fi, v.se);
  return 0; 
}