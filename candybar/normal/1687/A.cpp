/*
start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n, k, a[maxn];
ll sum[maxn];

void solve() {
  scanf("%d%d", &n, &k);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    sum[i] = sum[i - 1] + a[i];
    int lb = max(1, i - k + 1);
    chmax(ans, sum[i] - sum[lb - 1]
      + ll(k - (i - lb + 1) + k - 1) * (i - lb + 1) / 2);
  }
  printf("%lld\n", ans);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}