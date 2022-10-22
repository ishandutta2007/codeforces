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

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  ll n, m, a;
  scanf("%lld%lld%lld", &n, &m, &a);
  printf("%lld\n", (n + a - 1) / a * ((m + a - 1) / a));
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}