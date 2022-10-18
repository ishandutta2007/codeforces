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
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

char s1[110000], s2[110000];
int len, a, b;

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s1), gets(s2);
  len=strlen(s1);
  for (i=0; i<len; i++)
    if (s1[i]!=s2[i])
      (s1[i]=='4')?(a++):(b++);
  printf("%d\n", max(a,b));
  return 0;
}