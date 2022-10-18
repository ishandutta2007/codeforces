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
#define mod (1000000007ll)
#define pb push_back
#define mp make_pair

using namespace std;

long long A[70][2][2], B[2][2], C[2][2];

int main()
{
  int i, j, k;
  long long n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  A[0][0][0]=3, A[0][0][1]=1;
  A[0][1][0]=1, A[0][1][1]=3;
  for (i=0; i<65; i++)
    for (j=0; j<2; j++)
      for (k=0; k<2; k++)
        A[i+1][j][k]=(A[i][j][0]*A[i][0][k]+A[i][j][1]*A[i][1][k])%mod;
  B[0][0]=1, B[1][1]=1;
  cin>>n;
  for (i=0; i<60; i++)
    if (n&(1ll<<i))
    {
      for (j=0; j<2; j++)
        for (k=0; k<2; k++)
          C[j][k]=(B[j][0]*A[i][0][k]+B[j][1]*A[i][1][k])%mod;
      memcpy(B,C,sizeof(C));
    }
  printf("%I64d\n", B[0][0]);
  return 0;
}