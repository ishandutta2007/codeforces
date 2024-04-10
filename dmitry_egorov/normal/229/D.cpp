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

int n, S[5100], D[5100][5100];

int main()
{
  int i, j, k, tmp;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &tmp), S[i+1]=S[i]+tmp;
  for (i=1; i<=n; i++)
  {
    for (j=i-1, k=j-1; j>0; j--)
    {
      if (k==j)
        k--;
      while (k>0 && S[i]-S[j]>=S[j]-S[k-1])
        k--;
      (S[i]-S[j]>=S[j]-S[k])?(D[i][j]=D[j][k]+i-j-1):(D[i][j]=inf);
    }
    D[i][0]=i-1;
    for (j=i-2; j>=0; j--) 
      D[i][j]=min(D[i][j],D[i][j+1]);
  }
  printf("%d\n", D[n][0]);  
  return 0;
}