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

int A[60];

int main()
{
  int i, n, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  if (A[k-1]>0)
  {
    i=k-1;
    while (i<n-1 && A[k-1]==A[i+1])
      i++;
    printf("%d\n", i+1);
    return 0;
  }
  while (k>0 && A[k-1]==0)
    k--;
  printf("%d\n", k);
  return 0;
}