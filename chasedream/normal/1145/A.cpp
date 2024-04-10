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
 
const int N = 20;
int a[N], n;

int dfs(int l, int r) {
  if (l == r) return 1;
  int ok = 1;
  for (int i = l; i < r; i++)
    if (a[i] > a[i + 1]) ok = 0;
  if (ok) return r - l + 1;
  else {
    int mid = (l + r) >> 1;
    return max(dfs(l, mid), dfs(mid + 1, r));
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  printf("%d\n", dfs(1, n));
  return 0;
}