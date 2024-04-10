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
#define mod (1000000007)

using namespace std;

int D[5100][5100];
char s[5100], l[5100];
int ls, ll;

inline int norm (int a)
{
  return (a>=mod)?(a-mod):(a);
}

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), gets(l), ls=strlen(s), ll=strlen(l);
  for (i=1; i<=ls; i++)
    for (j=1; j<=ll; j++)
    {
      D[i][j]=D[i][j-1];
      if (s[i-1]==l[j-1])
        D[i][j]+=1+D[i-1][j-1], D[i][j]=norm(D[i][j]);
    }
  int res=0;
  for (i=0; i<=ls; i++)
    res+=D[i][ll], res=norm(res);
  printf("%d\n", res);
  return 0;
}