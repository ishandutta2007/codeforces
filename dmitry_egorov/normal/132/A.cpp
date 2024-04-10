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

char s[260];
int A[260], l;

int rev (int a)
{
  int res=0;
  for (int i=0; i<8; i++)
    if (a&(1<<i))
      res+=(1<<(7-i));
  return res;
}

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s);
  l=strlen(s);
  for (A[0]=(256-rev((int)s[0]))%256, i=1; i<l; i++)
    A[i]=(rev((int)s[i-1])-rev((int)s[i])+512)%256;
  for (i=0; i<l; i++)
    printf("%d\n", A[i]);
  return 0;
}