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

int A[110][110], N[2], S[2][110], U[2][110];

int main()
{
  int i, j, cnt, sum;
  pair <int, int> p;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &N[0], &N[1]);
  for (i=0; i<N[0]; i++)
    for (j=0; j<N[1]; j++)
      scanf("%d", &A[i][j]), S[0][i]+=A[i][j], S[1][j]+=A[i][j];
  while (true)
  {                   
    sum=0, p=mp(-1,-1);
    for (i=0; i<2; i++)
      for (j=0; j<N[i]; j++)
        if (sum>S[i][j])
         sum=S[i][j], p=mp(i,j);
    if (sum>=0)
      break;  
    U[p.first][p.second]^=1;
    if (p.first==0)
      for (S[0][p.second]=-S[0][p.second], i=0; i<N[1]; i++)
        S[1][i]-=(A[p.second][i]+A[p.second][i]), A[p.second][i]=-A[p.second][i];       
    else
      for (S[1][p.second]=-S[1][p.second], i=0; i<N[0]; i++)
        S[0][i]-=(A[i][p.second]+A[i][p.second]), A[i][p.second]=-A[i][p.second];       
  }    
  for (i=0; i<2; i++)
  {
    for (cnt=0, j=0; j<N[i]; j++)
      if (U[i][j])
        cnt++;
    printf("%d ", cnt);
    for (j=0; j<N[i]; j++)
      if (U[i][j])
        printf("%d ", j+1);
    printf("\n");
  }
  return 0;
}