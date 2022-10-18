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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int A[2200];

int main()
{
  int n, i, j, cnt, res=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=1; i<=n; i++)
    scanf("%d", &A[i]);
  for (i=1; i<=n; i++)
  {
    cnt=0, j=i;
    while (j!=-1)
      j=A[j], cnt++;
    res=max(res,cnt);
  }
  printf("%d\n", res);
  return 0;
}