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

long long m, A[32][2][2], R[2][2], T[2][2];
int n;

int main()
{
  int i, j, k, t;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>n>>m;
  R[0][0]=1%m, R[1][1]=1%m, A[0][0][0]=3%m, A[0][0][1]=2%m, A[0][1][1]=1%m;
  for (i=1; i<32; i++)
    for (j=0; j<2; j++)
      for (k=0; k<2; k++)
        for (t=0; t<2; t++)
          A[i][j][k]+=A[i-1][j][t]*A[i-1][t][k], A[i][j][k]%=m;
  for (i=0; i<32;i++)
    if (n&(1<<i))
    {
      for (j=0; j<2; j++)
        for (k=0; k<2; k++)
          for (t=0; t<2; t++)
            T[j][k]+=R[j][t]*A[i][t][k], T[j][k]%=m;
      memcpy(R,T,sizeof(T));
      memset(T,0,sizeof(T));
    }        
  printf("%d\n", (int)R[0][1]);
  return 0;
}