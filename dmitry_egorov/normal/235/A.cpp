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

long long res;

long long lcm (long long a, long long b)
{
  return (a*b)/__gcd(a,b);
}

int main()
{
  int i, j, k, t, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  t=min(50,n);
  for (i=0; i<t; i++)
    for (j=i; j<t; j++)
      for (k=j; k<t; k++)
        res=max(res,lcm(n-i,lcm(n-j,n-k)));
  cout<<res<<endl;
  return 0;
}