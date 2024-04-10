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

long long A[110000], S[110000];

int main()
{
  long long coef, np, p, d, res, res0=0ll;
  int q, n, i, x, k;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &x), A[i]=x;
  sort(A,A+n), reverse(A,A+n);
  for (i=0; i<n; i++)
    res0+=A[i]*i;
  for (i=1; i<=n; i++)
    S[i]=S[i-1]+A[i-1];
  scanf("%d", &q);
  while (q>0)
  {
    scanf("%d", &k), q--;
    if (k==1)
    {
      printf("%I64d\n", res0);
      continue;
    }
    p=0ll, d=1ll, res=0ll, coef=0ll;
    while (p<n)
      np=min((long long)n,p+d), d*=k, res+=coef*(S[np]-S[p]), coef++, p=np;
    printf("%I64d ", res);
  }
  printf("\n");
  return 0;
}