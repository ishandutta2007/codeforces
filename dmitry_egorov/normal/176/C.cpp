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

int main()
{
  int n, m, xf, yf, xs, ys;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d%d%d%d", &n, &m, &xf, &yf, &xs, &ys);
  int dx=abs(xf-xs), dy=abs(yf-ys);
  if (((dx==4 && dy==3) || (dx==3 && dy==4)))
  {
    puts("Second");
    return 0;
  }
  (max(dx,dy)<=3 || (max(dx,dy)==4 && min(dx,dy)<=3))?(puts("First")):(puts("Second"));
  return 0;
}