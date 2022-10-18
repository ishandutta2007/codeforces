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

void write (long long i, int st)
{
  if (st<8)
    write(i/10ll,st+1);
  printf("%I64d", i%(10ll));
}

int main()
{
  long long i, a, b, m, d;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%I64d%I64d", &a, &b, &m);
  for (d=1, i=0; i<9; i++)
    d=(d*10ll)%m;
  for (i=0; i<=min(a,m); i++)
  {
    if (((m-((i*d)%m))%m)>b)
    {
      printf("1 ");
      write(i,0);
      printf("\n");
      return 0;
    }
  }
  puts("2");
  return 0;
}