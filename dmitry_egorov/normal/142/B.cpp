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

int solve (int n, int m)
{
  if (n>m)
    swap(n,m);
  if (n==1)
    return m;
  if (n==2)
  {
    int t;
    t=2*(m/4), m%=4;
    t+=min(2,m);
    return 2*t;
  }
  return (n*m+1)/2;
}

int main()
{
  int n, m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  printf("%d\n", solve(n,m));
  return 0;
}