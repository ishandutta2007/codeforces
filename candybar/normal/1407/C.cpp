#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 10005
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;

int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}

int n, p[maxn];
bool app[maxn];
set<int> S;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) S.insert(i);
  while (S.size() > 1) {
    int i = *S.begin();
    S.erase(S.begin());
    int j = *S.begin();
    S.insert(i);
    int i_mod_j = query(i, j), j_mod_i = query(j, i);
    if (i_mod_j < j_mod_i) {
      p[j] = j_mod_i;
      S.erase(j);
    } else {
      p[i] = i_mod_j;
      S.erase(i);
    }
  }
  for (int i = 1; i <= n; i++) app[p[i]] = true;
  for (int i = 1; i <= n; i++) {
    if (!p[i]) {
      for (p[i] = 1; app[p[i]]; p[i]++);
      break;
    }
  }
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d%c", p[i], i == n ? '\n' : ' ');
  return 0;
}