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

#define maxn 1000005
const int mod = 998244353;
int n, k, a[maxn];

void solve() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = n; i > n - k; i--) {
    if (a[i] >= 1) {
      puts("0");
      return;
    }
  }
  int ans = 1;
  for (int i = 1; i <= k; i++)
    ans = (ll)ans * i % mod;
  for (int i = 1; i <= n - k; i++) {
    if (a[i] == -1)
      ans = (ll)ans * (k + i) % mod;
    else if (a[i] == 0)
      ans = (ll)ans * (k + 1) % mod;
  }
  printf("%d\n", ans);
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