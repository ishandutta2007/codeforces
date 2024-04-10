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

int main()
{
  long long n, x, y;
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%I64d%I64d", &n, &x, &y);
  if (n==1ll)
  {
    if (y*y>=x)
      printf("%I64d\n", y);
    else
      puts("-1");
    return 0;
  }  
  y-=(n-1ll);
  if (y<=0ll)
  {
    puts("-1");
    return 0;
  }
  if (n-1ll+(y*y)<x)
  {
    puts("-1");
    return 0;
  }
  printf("%I64d\n", y);
  for (i=0; i<n-1; i++)
    printf("%I64d\n", 1ll);
  return 0;
}