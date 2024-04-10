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
  int i, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  if (n%2==0)
  {
    puts("-1");
    return 0;
  }
  for (i=0; i<n; i++)
    printf("%d ", i);
  printf("\n");
  for (i=0; i<n; i++)
    printf("%d ", i);
  printf("\n");
  for (i=0; i<n; i++)
    printf("%d ", (2*i)%n);
  printf("\n");
  return 0;
}