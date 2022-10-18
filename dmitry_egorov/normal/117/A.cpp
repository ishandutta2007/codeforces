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
  int i, n, m, t, s, f, a, b;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
  {
    scanf("%d%d%d", &s, &f, &t);
    s--, f--;
    if (s==f)
    {
      printf("%d\n", t);
      continue;
    }
    a=s+2*(m-1)*(t/(2*(m-1)));
    while (a>=t)
      a-=2*(m-1);
    while (a<t)
      a+=2*(m-1);
    b=2*(m-1)-s+2*(m-1)*(t/(2*(m-1)));
    while (b>=t)
      b-=2*(m-1);
    while (b<t)
      b+=2*(m-1);
    //cerr<<a<<" "<<b<<endl;
    if (a<=b)
    {
      if (f>s)
        printf("%d\n", a+f-s);
      else
        printf("%d\n", a+2*(m-1)-f-s);
    }
    else
    {
      if (f<s)
        printf("%d\n", b+s-f);
      else
        printf("%d\n", b+s+f);
    }
  }
  return 0;
}