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

int A[10];

int main()
{
  int res=0, i, x, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &x), A[x]++;
  res+=A[4];
  res+=A[3], A[1]-=min(A[3],A[1]);
  res+=A[2]/2, A[2]%=2;
  A[1]+=2*A[2], res+=(A[1]+3)/4;
  printf("%d\n", res);
  return 0;
}