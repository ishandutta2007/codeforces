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

int a, b, A[110];

int main()
{
  int i, n, t=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n);
  for (i=0; i<n; i++)
  {
    t+=A[i];
    if (t<=710)
      a++, b+=max(0,t-350);
  }
  printf("%d %d \n", a, b);
  return 0;
}