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

int A[110000], B[110000], cnt;

int main()
{
  int i, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]), A[i]--, B[i]=A[i];
  sort(B,B+n);
  for (i=0; i<n; i++)
    if (A[i]!=B[i])
      cnt++;
  (cnt>2)?(puts("NO")):(puts("YES"));
  return 0;
}