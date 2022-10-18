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
#define inf ((int)2e9)
#define pb push_back
#define mp make_pair

using namespace std;

int D[1100], n, k;
int res, S[1100], c, f;

int main()
{
  int i; 
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%d", &D[i]);
  for (i=0; i<n; i++)
    scanf("%d", &S[i]);
  for (i=0; i<n; i++)
  {
    c=max(c,S[i]), f+=S[i];
    while (f<D[i])
      f+=c, res+=k;
    res+=D[i], f-=D[i];
  }  
  printf("%d\n", res);
  return 0;
}