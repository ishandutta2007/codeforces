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


char s[110000];
int pos, tmp;

int main()
{
  int len;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s), len=strlen(s);
  while (pos<len)
  {
    if (s[pos]==' ')
    {
      pos++;
      continue;
    }
    if (s[pos]=='"')
    {
      pos++, tmp=pos;
      while (s[pos]!='"')
        pos++;
      printf("<%s>\n", (string(s+tmp,s+pos)).c_str()), pos++;
      continue;
    }
    tmp=pos;
    while (pos<len && s[pos]!=' ')
      pos++;
    printf("<%s>\n", (string(s+tmp,s+pos)).c_str()), pos++;
  }
  return 0;
}