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
#include <assert.h>

#define MPI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int norm (int x, int l, int r)
{
  if (x<l)
    return l;
  if (x>r)
    return r;
  return x;
}

int main()
{
  int n, m, a, b, d, x, y, xm, ym;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d %d%d %d%d", &n, &m, &x, &y, &a, &b);
  d=__gcd(a,b), a/=d, b/=d, d=min(n/a,m/b), a*=d, b*=d;
  xm=x-(a+1)/2, ym=y-(b+1)/2;
  xm=norm(xm,0,n-a), ym=norm(ym,0,m-b);
  printf("%d %d %d %d\n", xm, ym, xm+a, ym+b);
  return 0;
}