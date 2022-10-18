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

long long mask, A[110000], tmp, B[110000];
int e;

int main()
{
  int i, j, n, k, x;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    for (A[i]=0, j=0; j<4; j++)
      (j)?(scanf(".%d", &x)):(scanf("%d", &x)), A[i]*=256, A[i]+=x;
  sort(A,A+n);
  for (i=1; i<32; i++)
  {
    for (mask=(1ll<<32)-(1ll<<(32-i)), e=0, j=0; j<n; j++)
    {
      tmp=A[j]&mask;
      if (e==0 || B[e-1]!=tmp)
        B[e++]=tmp;
    }
    if (e==k)
    {
      for (j=0; j<4; j++)
        printf("%I64d%c", (mask>>(24-8*j))&255, ".\n"[j==3]);
      return 0;
    }
  }
  puts("-1");
  return 0;
}