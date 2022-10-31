//
//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 400005;

int tot, son[N << 1], nxt[N << 1], head[N];
int tot2, son2[N << 1], nxt2[N << 1], head2[N];
int a[N];

void add(int u, int v) {
  son[++tot] = v, nxt[tot] = head[u], head[u] = tot;
}
void add2(int u, int v) {
  son2[++tot2] = v, nxt2[tot2] = head2[u], head2[u] = tot2;
}

void rebuild(int u, int fa, int col) {
  for (int i = head[u]; i; i = nxt[i]) {
    int v = son[i];
    if (v == fa) continue;
    if (a[col] == a[v]) rebuild(v, u, col);
    else {
      add2(col, v); add2(v, col);
      rebuild(v, u, v);
    } 
  }
}

int dp[N], ans;
void dfs(int u, int fa) {
  for (int i = head2[u]; i; i = nxt2[i]) {
    int v = son2[i];
    if (v == fa) continue;
    dfs(v, u);
    ans = max(ans, dp[u] + dp[v] + 1);
    dp[u] = max(dp[u], dp[v] + 1);
  }
}

int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i < n; i++) {
    int u, v; scanf("%d%d", &u, &v);
    add(u, v); add(v, u);
  }
  rebuild(1, 1, 1);
  dfs(1, 0);

  printf("%d\n", (ans + 1) >> 1);
  return 0;
}