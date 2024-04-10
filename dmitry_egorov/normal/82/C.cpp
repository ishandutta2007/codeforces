#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

struct mp 
{
  short id, pr;
};

bool operator < (mp i, mp j)
{
  return i.pr<j.pr;
}

int Dest[11000], Next[11000], Head[5500], C[11000], N[5500], e;
int Prev[5500], Ans[5500];
mp A[5500][5500], B[5500][5500];
int E[5500], En[5500], day=1;
bool fl=1;

void add (int v1, int v2, int c)
{
  C[e]=c;
  Dest[e]=v2;
  Next[e]=Head[v1];
  Head[v1]=e;
  e++;
}

void dfs (int v)
{
  int r;
  for (r=Head[v]; r!=-1; r=Next[r])
    if (Prev[Dest[r]]==-1)
      N[Dest[r]]=C[r], Prev[Dest[r]]=v, dfs(Dest[r]);
}

int main() {
  int i, j, c, v1, v2, n;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  memset(Head,-1,sizeof(Head));
  scanf("%d", &n);
  for (i=0; i<n; i++)
    E[i]=1, scanf("%d", &A[i][0].pr), A[i][0].id=i;
  for (i=0; i<n-1; i++)
  {
    scanf("%d%d%d", &v1, &v2, &c);
    v1--, v2--;
    add(v1,v2,c);
    add(v2,v1,c);
  }
  memset(Prev,-1,sizeof(Prev));
  Prev[0]=0;
  dfs(0);
  while (fl)
  {
    fl=0;
    memset(En,0,sizeof(En));
    for (i=0; i<E[0]; i++)
      Ans[A[0][i].id]=day-1;
    for (i=1; i<n; i++)
      if (E[i]!=0)
      {
        sort(A[i],A[i]+E[i]);
        for (j=0; j<min(N[i],E[i]); j++)
          B[Prev[i]][En[Prev[i]]]=A[i][j], En[Prev[i]]++;
        for ( ; j<E[i]; j++)
          B[i][En[i]]=A[i][j], En[i]++;
        fl=1;
      }
    for (i=0; i<n; i++)
    {
      E[i]=En[i];
      for (j=0; j<E[i]; j++)
        A[i][j]=B[i][j];
    }
    day++;
  }
  for (i=0; i<n; i++)
    printf("%d ", Ans[i]);
  printf("\n");
  return 0;
}