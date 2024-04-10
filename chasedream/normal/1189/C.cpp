%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

const int maxn = 100005;
int a[maxn], b[maxn], sum[maxn];
long long dp[maxn][25];
int n;
 
void pre() {
  for (int i = 1; i <= n; i++)
    dp[i][0] = 0;
  for (int k = 1; k <= 20; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      dp[i][k] = dp[i][k - 1] + dp[i + (1 << (k - 1))][k - 1];
      int v1 = sum[i + (1 << (k - 1)) - 1] - sum[i - 1]; v1 %= 10;
      int v2 = sum[i + (1 << k) - 1] - sum[i + (1 << (k - 1)) - 1]; v2 %= 10;
      if (v1 + v2 >= 10) dp[i][k]++;
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
  }
  pre();
  int q; scanf("%d", &q);
  while (q--) {
    int l, r; scanf("%d%d", &l, &r);
    int Log = (int)log2(r - l + 1);
    printf("%lld\n", dp[l][Log]);
  }
  return 0;
}
// zhouzhuan, 233