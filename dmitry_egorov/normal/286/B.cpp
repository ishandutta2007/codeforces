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

int A[2100000];

int main()
{
  int i, n, it, k, m, to;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=1; i<=n; i++)
    A[i]=i;
  for (it=0, m=2; m<=n; m++, it++)
  {
  /*for (i=it+1; i<=it+n; i++)
    printf("%d ", A[i]);
  printf("\n");*/

    k=((n-1)/m)*m+1;
    while (k+m<=n)
      k+=m;
    for ( ; k>=1; k-=m)
      to=min(n,k+m-1), A[to+it+1]=A[k+it], A[k+it]=0;// cerr<<"!!! "<<k<<" "<<to<<endl;
  }
  for (i=it+1; i<=it+n; i++)
    printf("%d ", A[i]);
  printf("\n");
  //cerr<<clock()<<endl;
  return 0;
}