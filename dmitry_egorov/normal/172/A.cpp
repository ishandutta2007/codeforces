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

char s[50], ns[50];

int main()
{
  int res, i, n, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d ", &n);
  for (gets(s), res=strlen(s), i=1; i<n; res=j, i++)
  {
    gets(ns), res=min(res,(int)strlen(ns)), j=0;
    while (j<res && s[j]==ns[j])
      j++;      
  }
  printf("%d\n", res);
  return 0;
}