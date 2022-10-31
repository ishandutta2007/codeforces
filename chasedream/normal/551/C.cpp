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
 
const int N = 100005;

int a[N], b[N];
int n, m;

bool check(ll mid) {
  for (int i = 1; i <= n; i++) b[i] = a[i];
  
  int fake = n;
  for (int i = 1; i <= m; i++) {
    while (!b[fake] && fake > 0) fake--;
    if (fake == 0) return 1;
    ll times = mid - fake;
    if (times < 0) return 0;
    while (times >= 0) {
      if (b[fake] > times) {
        b[fake] -= times;
        break;
      }
      else {
        times -= b[fake];
        b[fake] = 0;
        while (!b[fake] && fake > 0) fake--;
        if (fake == 0) return 1;
      }
    }
  }
  while (!b[fake] && fake > 0) fake--;
  return (fake == 0);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  
  ll l = 0, r = 1e18;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) r = mid;
    else l = mid + 1;
  }
  printf("%lld\n", l);
  return 0; 
}