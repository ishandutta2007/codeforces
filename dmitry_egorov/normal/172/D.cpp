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

int u[12345678];
long long res;

int main()
{
  int i, a, n, j, s;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (i=1; i*i<12345678; i++)
    for (s=i*i, j=s; j<12345678; j+=s)
      u[j]=s;
  scanf("%d%d", &a, &n);
  for (i=0; i<n; i++)
    res+=(a+i)/u[a+i];
  printf("%I64d\n", res);
  return 0;
}