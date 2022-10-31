%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128

const int N = 20;

unordered_map <ll, int> v[N][N];

int n, m, half;
ll a[N][N], k, ans;

void dfs(int x, int y, ll val, int cnt) {
  val ^= a[x][y];
  if (cnt == half) {
    v[x][y][val]++;
    return ;
  } 
  if (x + 1 < n) dfs(x + 1, y, val, cnt + 1);
  if (y + 1 < m) dfs(x, y + 1, val, cnt + 1);
}

void dfs2(int x, int y, ll val, int cnt) {
  if (cnt == n + m - 2 - half) {
    if (v[x][y].count(k ^ val)) {
      ans += v[x][y][k ^ val];
    }
    return ;
  }
  
  val ^= a[x][y];
  if (x > 0) dfs2(x - 1, y, val, cnt + 1);
  if (y > 0) dfs2(x, y - 1, val, cnt + 1);
}

int main() {
  scanf("%d%d%lld", &n, &m, &k);
  half = (n + m - 2) / 2;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      scanf("%lld", &a[i][j]);
    }
  
  dfs(0, 0, 0, 0);
  dfs2(n - 1, m - 1, 0, 0);
  
  printf("%lld\n", ans);
  return 0;
}