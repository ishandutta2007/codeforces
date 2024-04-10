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

bool u[2234567];
int A[1234567], res, P[40], N[40], ep, en;

int main()
{
  int i, j, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  u[A[0]]=1, P[0]=A[0], ep=1;
  for (i=1; i<n; i++)
  {
    for (N[0]=A[i], en=1, j=0; j<ep; j++)
      N[en++]=(A[i]|P[j]);
    for (N[en]=inf, ep=0, j=0; j<en; j++)
      if (N[j]!=N[j+1])
        P[ep++]=N[j];
    //cerr<<en<<" "<<ep<<endl;
    for (j=0; j<ep; j++)
      u[P[j]]=1;//, cerr<<P[j]<<endl;
  }
  for (i=0; i<2234567; i++)
    if (u[i])
      res++;
  printf("%d\n", res);
  return 0;
}