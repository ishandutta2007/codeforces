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

#define maxn 1000005

int n, c, cnt[maxn * 2];

void solve() {
  scanf("%d%d", &n, &c);
  for (int i = 0; i <= 2 * c; i++)
    cnt[i] = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    scanf("%d", &a);
    cnt[a] = 1;
  }
  for (int i = 1; i <= 2 * c; i++)
    cnt[i] += cnt[i - 1];
  for (int i = 1; i <= c; i++) {
    for (int j = 1; j * i <= c; j++) {
      if (cnt[i] == cnt[i - 1] && cnt[j] != cnt[j - 1] && cnt[j * (i + 1) - 1] != cnt[j * i - 1]) {
        puts("No");
        return;
      }
    }
  }
  puts("Yes");
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}