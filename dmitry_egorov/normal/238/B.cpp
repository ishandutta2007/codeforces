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

pair <int, int> A[110000];

int main()
{
  int n, i, h;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &h);
  if (n==2)
  {
    printf("0\n1 1\n");
    return 0;
  }
  for (i=0; i<n; i++)
    scanf("%d", &A[i].first), A[i].second=i;
  sort(A,A+n);
  reverse(A,A+n);
  int f1=(A[0].first+A[1].first)-(A[n-2].first+A[n-1].first);
  int f2=max(A[0].first+A[1].first,A[0].first+A[n-1].first+h)-min(A[n-1].first+A[n-2].first+h,A[n-2].first+A[n-3].first);
/*  if (n>3)
  {
  int f3=max(A[0].first+A[1].first,A[0].first+A[n-2].first+h)-min(A[n-1].first+A[n-2].first+h,A[n-1].first+A[n-3].first);
  if (f3<f1 && f3<f2)
  {
    printf("%d\n", f3);
    for (i=0; i<n; i++)
      (A[n-2].second==i)?(printf("2 ")):(printf("1 "));
    printf("\n");

    return 0;
  } 
  }  */
  if (f1<f2)
  {
    printf("%d\n", f1);
    for (i=0; i<n; i++)
      printf("1 ");
    printf("\n");
    return 0;
  }
    printf("%d\n", f2);
    for (i=0; i<n; i++)
      (A[n-1].second==i)?(printf("2 ")):(printf("1 "));
    printf("\n");

  return 0;
}