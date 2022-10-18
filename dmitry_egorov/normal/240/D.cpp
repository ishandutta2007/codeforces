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

int N[2], E[2], e, A[2][110000], B[210000], C[210000];
vector <int> V;

int main()
{
  int i, j, vl=1;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  for (i=0; i<2; reverse(A[i],A[i]+N[i]), i++)
    for (scanf("%d", &N[i]), j=0; j<N[i]; j++)
      scanf("%d", &A[i][j]);
  while (E[0]+E[1]<N[0]+N[1])
  {
    vl^=1;
    while (E[0]<N[0] && A[0][E[0]]==vl)
      C[e]=vl, B[e++]=N[0]-E[0], E[0]++;
    while (E[1]<N[1] && A[1][E[1]]==vl)
      C[e]=vl, B[e++]=N[1]+N[0]-E[1], E[1]++;
  }
  reverse(B,B+e);
  for (i=0; i<N[0]+N[1]; i++)
    printf("%d ", B[i]);
  printf("\n");
  if (C[0]==1)  
    V.pb(N[0]+N[1]);
  for (i=1; i<N[0]+N[1]; i++)
    if (C[i]!=C[i-1])
      V.pb(N[0]+N[1]-i);
  reverse(V.begin(),V.end());
  printf("%d\n", V.size());
  for (i=0; i<(int)V.size(); i++)
    printf("%d ", V[i]);
  printf("\n");
  return 0;
}