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

bool G[110];
int n, m, k, E[110], Minv[110], Maxv[110];
char s[210];

int main()
{
  int i, j, tmp, cnt, mv, Mv;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d ", &m, &k), m-=k;
  for (i=0; i<k; i++)
    scanf("%d ", &tmp), G[tmp]=1;
  scanf("%d ", &n);
  if (n==1)
  {
    puts("0");
    return 0;
  }
  for (i=0; i<n; i++)
  {
    for (gets(s), scanf("%d ", &E[i]), cnt=0, j=0; j<E[i]; j++)
    {
      scanf("%d ", &tmp);
      if (tmp==0)
        cnt++;
      if (G[tmp])
        Minv[i]++, Maxv[i]++;
    }
    Minv[i]=max(Minv[i],E[i]-m), Maxv[i]=min(Maxv[i]+cnt,k);
  }
  for (i=0; i<n; i++)
  {
    for (mv=-1, Mv=-1, j=0; j<n; j++)
      if (i!=j)
        mv=max(mv,Minv[j]), Mv=max(Mv,Maxv[j]);
    if (Minv[i]>=Mv)
    {
      puts("0");
      continue;
    }
    (Maxv[i]<mv)?(puts("1")):(puts("2"));
  }
  return 0;
}