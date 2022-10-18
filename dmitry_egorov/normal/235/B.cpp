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

long double res, A[110000];

int main()
{
  int i, n;
  long double p;
  double tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%lf", &tmp), A[i]=tmp, res-=A[i];
  for (p=0.0, i=0; i<n; res+=2.0*p, i++)
    p++, p*=A[i];
  printf("%.8lf\n", (double)res);
  return 0;
}