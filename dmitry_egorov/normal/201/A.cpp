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

int calc (int n)
{
  if (n&1)
    return (n*n+1)/2;
  return 4*((((n/2)-1)*((n/2)-1)+1)/2);
}

int main()
{

  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  int x, n=1, res=inf;
  scanf("%d", &x);
  for (n=1; n<1000; n++)
    if (n!=2 && calc(n)>=x && (calc(n)%4==x%4 || n%2==1) && (x!=3 || n!=3))
      res=min(res,n);
  printf("%d\n", res);
  return 0;
}