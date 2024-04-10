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

const int N = 105;

int dp[N][25], a[N][N];
int n, m;

void work() {
  memset(dp, 0, sizeof(dp));

  read(n, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
    } 
  }
  
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < (1 << n); j++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        if ((j & mask) != 0) continue;
      
        for (int k = 0; k < n; k++) {
          int suc = 0;
          for (int l = 0; l < n; l++) {
            if (j & (1 << l))
              suc += a[(l + k) % n + 1][i]; 
          }
          
          dp[i][j ^ mask] = max(dp[i][j ^ mask], dp[i - 1][mask] + suc);
        }
      }
    }
  }
  
  printf("%d\n", dp[m][(1 << n) - 1]);
  return ;
}

int main() {
  int T; read(T);
  while (T--) work();
  return 0;
}