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

bool C[110][210];
bool u[210];
int Q[110], A[110], Inv[110];

int main()
{
  int n, k, i, j, f, b;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%d", &Q[i]), Q[i]--, Inv[Q[i]]=i;
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), A[i]--;
  for (i=0; i<=2*k; i++)
    u[i]=1;
  for (i=0; i<n; i++)
    for (f=i, b=i, j=0; j<=k; f=Q[f], b=Inv[b], j++)
    {
      if (f!=A[i])
        u[k+j]=0;
      if (b!=A[i])
        u[k-j]=0;
    }

  for (C[0][k]=1, i=0; i<k; i++)
    for (j=1; j<=2*k; j++)
      if (C[i][j] && (!u[j]))
        C[i+1][j-1]=1, C[i+1][j+1]=1;
  for (i=0; i<=2*k; i++)
    if (C[k][i] && u[i])
    {
      puts("YES");
      return 0;
    }
  puts("NO");
  return 0;
}