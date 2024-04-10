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

int A[210];

int main()
{
  int cnt=0, i, n, m=inf, res=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<2*n-1; i++)
  {
    scanf("%d", &A[i]), res+=abs(A[i]);
    if (A[i]<0)
      cnt++;
    m=min(m,abs(A[i]));
  }
  printf("%d\n", ((cnt&1)==1 && n%2==0)?(res-2*m):(res));
  return 0;
}