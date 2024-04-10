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

int A[110000];

int main()
{
  int a, b, r, m, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d%d", &a, &b, &m, &r);
  for (i=1; ; A[r]=i, i++)
  {
    r=(r*a+b)%m;
    if (A[r])
    {
      printf("%d\n", i-A[r]);
      return 0;
    }
  }
  assert(0);
  return 0;
}