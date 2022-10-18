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

int A[110];
char s[110][110];

int main()
{
  int i, k, j, n, cl=3;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &k);
  while (cl*(cl+1)*(cl-1)<=6*k)
    cl++;
  k-=(cl*(cl-1)*(cl-2))/6, n=cl;
  for (i=0; i<cl; i++)
    for (j=0; j<cl; j++)
      (i!=j)?(s[i][j]='1'):(s[i][j]='0');
  while (k>0)
  {
    n++;
    for (i=0; i<n; i++)
      s[n-1][i]='0', s[i][n-1]='0';
    j=1;
    while ((j+1)*j<=2*k)
      j++;
    for (k-=(j*(j-1))/2, i=0; i<j; i++)
      s[n-1][i]='1', s[i][n-1]='1';
  }
  printf("%d\n", n);
  for (i=0; i<n; i++)
    puts(s[i]);
  return 0;
}