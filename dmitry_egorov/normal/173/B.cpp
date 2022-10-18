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

int D[2100];
vector <int> G[2100];
char s[1100][1100];
int bq, eq, Q[2100];

int main()
{
  int n, m, i, j, v;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &m);
  for (i=0; i<n; i++)
    gets(s[i]);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      if (s[i][j]=='#')
        G[i].pb(n+j), G[n+j].pb(i);
  memset(D,-1,sizeof(D)), eq=1, D[0]=0;
  while (bq<eq)
  {
    v=Q[bq], bq++;
    for (i=0; i<(int)G[v].size(); i++)
      if (D[G[v][i]]==-1)
        D[G[v][i]]=D[v]+1, Q[eq++]=G[v][i];
  }
  printf("%d\n", D[n-1]);
  return 0;
}