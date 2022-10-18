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

char s1[1100], s2[1100];
int res1, res2;

bool win (char f, char s)
{
  return ((f=='R' && s=='S') || (f=='S' && s=='P') || (f=='P' && s=='R'));
}

int main()
{
  int n, d, cnt, i, l1, l2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d ", &n);
  gets(s1), l1=strlen(s1);
  gets(s2), l2=strlen(s2);
  d=__gcd(l1,l2);
  int tmp=l1*l2/d;
  for (i=0; i<min(n,tmp); i++)
  {
    cnt=(n-i+tmp-1)/tmp;
   // cerr<<i<<" "<<cnt<<endl;
    if (win(s1[i%l1],s2[i%l2]))
      res2+=cnt;
    if (win(s2[i%l2],s1[i%l1]))
      res1+=cnt;
    //cerr<<res1<<" "<<res2<<endl;
  }
  printf("%d %d\n", res1, res2);
  return 0;
}