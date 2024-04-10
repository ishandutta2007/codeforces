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
  int n, i, m=0, j, cnt;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &n);
  while ((1<<m)<n)
    m++;
  printf("%d\n", m);
  for (i=0; i<m; i++)
  {
    for (cnt=0, j=0; j<n; j++)
      if (j&(1<<i))
        cnt++;
    printf("%d ", cnt);
    for (cnt=0, j=0; j<n; j++)
      if (j&(1<<i))
        printf("%d ", j+1);
    printf("\n");
  }
  return 0;
}