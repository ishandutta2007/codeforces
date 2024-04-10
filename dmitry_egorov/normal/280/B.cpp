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

int res, A[110000];

int main()
{
  int n, m, d, it, i, last, pmax;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  bool fl=1;
  while (fl)
  {
    for (m=0, i=0; i<n; i++)
      m=max(m,A[i]);
    d=0;
    while (m>=(1<<(d+1)))
      d++;
    for (i=0; i<n; i++)
      if (!(A[i]&(1<<d)))
        fl=0;
    if (!fl)
      break;
    for (i=0; i<n; i++)
      A[i]^=(1<<d);
  }
  for (it=0; it<2; it++, reverse(A,A+n))
  {
    last=-1, pmax=-1;
    for (i=0; i<n; i++)
    {
      if (A[i]&(1<<d))
      {
        last=A[i], pmax=-1;
        continue;
      }
      if (A[i]>pmax)
        res=max(res,last^A[i]);
      pmax=max(pmax,A[i]);
    }
  }
  cout<<res<<endl;
  return 0;
}