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

int Snm[110], Tmp[110], Sz[110], n, m, sum;
bool Fl[110];

int SNM (int a)
{
  if (Snm[a]==a)
    return a;
  Snm[a]=SNM(Snm[a]);
  return Snm[a];
}

void join (int a, int b)
{
  a=SNM(a), b=SNM(b);
  if (a==b)
    return;
  Snm[b]=a;
}

int main()
{
  int i, j, cnt;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    Snm[i]=i;
  for (i=0; i<n; i++)
  {
    scanf("%d", &cnt);
    if (cnt==0)
    {
      sum++;
      continue;
    }
    for (j=0; j<cnt; j++)
      scanf("%d", &Tmp[j]), Tmp[j]--, Fl[Tmp[j]]=1;
    for (j=1; j<cnt; j++)
      join(Tmp[0],Tmp[j]);
  }
  if (sum==n)
  {
    printf("%d\n", n);
    return 0;
  }
  for (sum--, i=0; i<m; i++)
    if (Fl[i] && Snm[i]==i)
      sum++;
  printf("%d\n", sum);
  return 0;
}