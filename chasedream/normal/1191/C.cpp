%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
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
 
#define int long long
const int maxn = 1000005;
int a[maxn];
int n, m, k;
 
void rd() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++)
    cin >> a[i];
}
 
ll ans = 0, pp = 0;
 
void calc() {
  for (int i = 1; i <= m; i++) {
    int dd;
    if ((a[i] - pp) % k == 0) dd = (a[i] - pp) / k - 1;
    else dd = (a[i] - pp) / k;
    int tot = 1;
    while (a[i + 1] <= pp + (dd + 1) * k) {
      if (i >= m) break;
      i++, tot++;
    }
    ans++, pp += tot;
  }
  cout << ans << '\n';
}
 
signed main() {
  ios :: sync_with_stdio(false); cin.tie(0);
  return rd(), calc(), 0;
}