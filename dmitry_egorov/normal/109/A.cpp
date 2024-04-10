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
  int n, i, a, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=1; i<1234567; i++)
  {
    if (n<=7*i && n>=4*i && n%3==i%3)
    {
      a=(n-4*i)/3;
      for (j=0; j<i-a; j++)
        printf("4");
      for (j=0; j<a; j++)
        printf("7");
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}