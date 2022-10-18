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
  int n, k, i, j, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n-1; i++)
    A[i]=1;
  for (i=0; i<k; i++, printf("\n"))
    for (j=0; j<n; j++)
      t=n-1-min(A[j],n-1-j-A[j]), A[j]+=n-1-t, printf("%d ", t+1);
  return 0;
}