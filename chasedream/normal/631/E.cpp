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

const int maxn = 300005;
ll _max(ll x, ll y) {
  return x > y ? x : y;
}

struct ele {
  ll k, b;
} dot[maxn];

bool cmp(ele x,ele y) {
  return x.k != y.k ? x.k < y.k : x.b > y.b;
}

dd slope(int x, int y) {
  return (double)(dot[y].b - dot[x].b) / (dot[y].k - dot[x].k);
}

ll S[maxn], a[maxn], b[maxn], t, ans = -1e18, s;
int n, tp = 1;
dd x[maxn];


ll query(ll fuck) {
  ll d = lower_bound(x + 1, x + tp + 1, (dd)fuck) - x - 1;
  return fuck * dot[S[d]].k + dot[S[d]].b;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    dot[i].k = i; scanf("%lld", &a[i]);
    b[i] = b[i - 1] + a[i];
    dot[i].b = -b[i];
    s += a[i] * i;
  }
  
  S[1] = 1;
  for (int i = 2; i <= n; i++) {
    while (tp > 1 && slope(S[tp - 1], S[tp]) <= slope(S[tp], i)) tp--;
    S[++tp] = i;
  }
  
  for (int i = 2; i <= tp; i++) x[i] = -slope(S[i], S[i - 1]);
  
  x[1] = -1e18;
  for (int i = 1; i <= n; i++) {
    t = query(a[i]); t = max(t, 0ll);
    ans = max(ans, b[i] - a[i] * i + t);
  }
  printf("%lld\n", ans + s);
  return 0;
}