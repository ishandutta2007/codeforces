#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

long double a=1.0, b=1.0;
int A[1100], s;

int main()
{
  int i, n, m, h;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &h);
  for (i=1; i<=m; i++)
    scanf("%d", &A[i]), s+=A[i];
  A[h]--, n--, s--;
  if (s<n)
  {
    puts("-1\n");
    return 0;
  }
  if (s-A[h]<n)
  {
    puts("1.0\n");
    return 0;
  }
  for (i=1; i<=s; i++)
  {
    if (i>s-A[h]-n && i<=s-n)
      a*=(long double)i;
    if (i>s-A[h])
      b*=(long double)i;
  }
  printf("%.8lf\n", 1.0-((double)(a/b)));
  return 0;
}