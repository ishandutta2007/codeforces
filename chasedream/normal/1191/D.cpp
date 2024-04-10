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
#define win puts("sjfnb")
#define lose puts("cslnb")
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

#define int long long
ll a[100005], sum;
int n;
multiset <ll> se;

void calc() {
  ll tot = 0;
  for (int i = 1; i <= n; i++) {
    if (se.count(a[i]) > 1) {
      if (se.count(a[i]) >= 3) {
        lose;
        exit(0);
      }
      if ((tot != 0 && a[i] != tot)) {
        lose;
        exit(0);
      }
      tot = a[i];
    }
  }
  if (se.count(tot - 1)) {
    lose;
    exit(0);
  }
  ll ans = sum - (n * (n - 1) / 2);
  if (ans & 1) win;
  else lose;
  exit(0);
}

signed main() {
  scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
	  ll x; scanf("%lld", &x);
	  a[i] = x;
	  sum += a[i]; se.insert(a[i]);
  } 
  if (n == 1) {
    if (a[1] & 1) win;
    else lose;
    return 0;
  }
  
  if (se.count(0) > 1) {
    lose;
    return 0;
  }
  
  calc();
  return 0;
}