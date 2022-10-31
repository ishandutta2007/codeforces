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
 
const int maxn = 1000005;
int r[maxn], c[maxn], n, m;
char b[maxn];
 
char read_char() {
  for (;;) {
    char op = getchar();
    if (op == '.' || op == '*') return op;
  }
}
 
int id(int i, int j) {
  return (i - 1) * m + j;
}
 
int main() {
  //freopen("ans.txt", "w", stdout);
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
      r[i] = 0;
    for (int i = 1; i <= m; i++)
      c[i] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char a = read_char();
        b[id(i, j)] = a;
        if (a == '*') r[i]++, c[j]++;
      }
    }
    int ans = (n + m) << 1; 
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (b[id(i, j)] == '.') ans = min(ans, n - r[i] + m - c[j] - 1);
        else ans = min(ans, n - r[i] + m - c[j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
} 
// zhouzhuan, 233
// wlzhouzhuan, 23333333