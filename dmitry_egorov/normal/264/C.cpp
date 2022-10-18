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
#define inf ((long long)1e18)
#define pb push_back
#define mp make_pair

using namespace std;

long long A[110000], D[110000], a, b;
int C[110000], n, q;

int main()
{
  int i, c0, c1;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &q);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]);
  for (i=0; i<n; i++)
    scanf("%d", &C[i]);
  while (q>0)
  {
    q--, scanf("%I64d%I64d", &a, &b);
    for (i=1; i<=n; i++)
      D[i]=-inf;
    D[0]=0, c0=0, c1=1;
    for (i=0; i<n; i++)
    {
      if (C[i]==c0)
      {
        D[c0]=max(D[c0],max(D[c0]+A[i]*a,D[c1]+A[i]*b));
        continue;
      }
      D[C[i]]=max(D[C[i]],max(D[c0]+A[i]*b,D[C[i]]+A[i]*a));
      if (D[C[i]]>D[c1])
        c1=C[i];
      if (D[c0]<D[c1])
        swap(c0,c1);
    }
    printf("%I64d\n", D[c0]);
  }
  return 0;
}