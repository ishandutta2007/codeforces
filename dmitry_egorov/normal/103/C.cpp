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
  long long n, k, f, fk, p;
  int i, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%I64d%d", &n, &k, &t);
  f=n-k;
  int fl=k;
  k=min(f,k);             
  if (((f+k)%2ll)==1ll)
    k--;
  fk=f+k-(2ll*(k-1ll));
  for (i=0; i<t; i++)
  {
    if (!fl)
    {
      printf(".");
      continue;
    }
    scanf("%I64d", &p);
    if (p<fk && fk<=f+k)
    {
      printf(".");
      continue;
    }
    if (p<=f+k)
    {
      if (((fk%(2ll))==(p%(2ll))) && fk<=f+k)
        printf("X");
      else
        printf(".");  
    }
    else
      printf("X");
  }
  printf("\n");
  return 0;
}