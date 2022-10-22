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
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
int n, m;
vector<vector<int>> a;
vector<int> cs[maxn], rs[maxn];

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 100000; i++) {
    rs[i].clear();
    cs[i].clear();
  }
  a.resize(n + 2);
  for (int i = 0; i <= n + 1; i++)
    a[i].resize(m + 2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      cs[a[i][j]].push_back(j);
      rs[a[i][j]].push_back(i);
    }
  }
  ll ans = 0;
  for (int i = 1; i <= 100000; i++) {
    sort(rs[i].begin(), rs[i].end());
    for (int j = 1; j < (int)rs[i].size(); j++)
      ans += ll(rs[i][j] - rs[i][j - 1]) * j * (rs[i].size() - j);
    sort(cs[i].begin(), cs[i].end());
    for (int j = 1; j < (int)cs[i].size(); j++) 
      ans += ll(cs[i][j] - cs[i][j - 1]) * j * (cs[i].size() - j);
  }
  printf("%lld\n", ans);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  solve();
  return 0;
}