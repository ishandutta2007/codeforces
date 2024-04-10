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

int gcd (int a, int b)
{
  if (b==0)
    return a;
  return gcd(b,a%b);
}

int main()
{
  int n, a[2], i=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &a[0], &a[1], &n);
  while (n>0)
  {
    n-=gcd(a[i],n);
    i=1-i;
  }
  printf("%d\n", 1-i);
  return 0;
}