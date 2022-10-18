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

using namespace std;

long long gcd (long long a, long long b)
{
  if (b==0ll)
    return a;
  return gcd(b,a%b);
}

int main()
{
  long long a, b, c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%I64d", &a, &b);
  c=gcd(a,b);
  a/=c, b/=c;
  if (abs(a-b)==1ll)
  {
    printf("Equal\n");
    return 0;
  }
  if (a>b)
    printf("Masha\n");
  else
    printf("Dasha\n");
  return 0;
}