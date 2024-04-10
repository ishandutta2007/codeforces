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

int n;
char s[2][210000];
long double res=0.0;
long double coef[300];

long double mul (int a, int b)
{
  return (((long double)(a))*((long double)(b)));
}

int main()
{
  int i, j, id;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d ", &n);
  gets(s[0]), gets(s[1]);
  for (i=0; i<n; i++)
    if (s[0][i]==s[1][i])
      res+=mul(i+1,n-i);
  for (id=0; id<2; id++)
  {
    memset(coef,0,sizeof(coef));
    for (j=1; j<n; j++)
      coef[(int)s[1^id][j]]+=((long double)(n-j));
    for (i=0; i<n; i++)
      res+=coef[(int)s[id][i]]*((long double)(i+1)), coef[(int)s[1^id][i+1]]-=((long double)(n-i-1));
  }
  long double cf=0.0;
  for (i=1; i<=n; i++)
    cf+=mul(i,i);
  res/=cf;
  printf("%.8lf\n", (double)res);
  return 0;
}