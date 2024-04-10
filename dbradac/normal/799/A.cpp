#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR (i, 0, n)
#define _ << " _ " <<

#define TRACE(x) cerr << #x << " = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

// #define TRACE(x)
// #define debug(...)

using namespace std;

typedef long long llint;

int main(void) {
  int n, t, k, d;
  scanf("%d%d%d%d", &n, &t, &k, &d);
  
  int t1 = (n + k - 1) / k * t;
  if ((t1 - 1) / t * k + max(0, (t1 - 1 - d) / t * k) >= n)
    printf("YES\n");
  else printf("NO\n");
  
  return 0;
}