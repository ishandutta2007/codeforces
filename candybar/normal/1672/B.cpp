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
template <class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template <class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 200005
int n;
char s[maxn];

bool solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  if (s[n] == 'A')
    return false;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += s[i] == 'A' ? 1 : -1;
    if (cnt < 0)
      return false;
  }
  return true;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    puts(solve() ? "Yes" : "No");
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}