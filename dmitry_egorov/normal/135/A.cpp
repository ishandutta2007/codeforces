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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;
  
int A[110000];

int main()
{
  int i, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  sort(A,A+n);
  if (A[n-1]==1)
    A[n-1]=2;
  else
    A[n-1]=1;
  sort(A,A+n);
  for (i=0; i<n; i++)
    printf("%d ", A[i]);
  printf("\n");
  return 0;
}