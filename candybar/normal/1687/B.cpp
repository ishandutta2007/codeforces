/*
start thinking:
BULB:
result of thinking:

simulated Kruskal.

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

#define maxm 505
char s[maxm];

int n, m;
P el[maxm]; // (w, id)

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++)
      s[j] = "01"[i == j];
    printf("? %s\n", s + 1);
    fflush(stdout);
    int foo;
    scanf("%d", &foo);
    el[i] = {foo, i};
  }
  sort(el + 1, el + m + 1);
  for (int i = 1; i <= m; i++)
    s[i] = '0';
  int lst = 0;
  for (int i = 1; i <= m; i++) {
    s[el[i].second] = '1';
    printf("? %s\n", s + 1);
    fflush(stdout);
    int foo;
    scanf("%d", &foo);
    if (foo < lst + el[i].first)
      s[el[i].second] = '0';
    else
      lst = foo;
  }
  printf("! %d\n", lst);
  fflush(stdout);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}