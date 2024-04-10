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

int A[110000], res;

int main()
{
  int n, tmp, q=inf, i, j, c=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &tmp), q=min(q,tmp);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n,greater<int>());
  while (c<n)
  {
    for (j=0; j<q && c+j<n; j++)
      res+=A[c+j];
    c+=j;
    for (j=0; c<n && j<2; j++)
      c++;
  }
  printf("%d\n", res);
  return 0;
}