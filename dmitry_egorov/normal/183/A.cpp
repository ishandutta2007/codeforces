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

char s[10];
long long cnt1, cnt2, cnt3;

int main()
{
  int n, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d ", &n);
  for (i=0; i<n; i++)
  {
    gets(s);
    if (strlen(s)==4)
    {
      cnt3++;
      continue;
    }
    if ((s[0]=='U' && s[1]=='L') || (s[0]=='D' && s[1]=='R'))
      cnt1++;
    else
      cnt2++;
  }
  printf("%I64d\n", (1ll+cnt1+cnt3)*(1ll+cnt2+cnt3));
  return 0;
}