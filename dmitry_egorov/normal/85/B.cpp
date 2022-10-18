#include <iostream>
#include <stdio.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <math.h>
#include <utility>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int n, k[3], c[3];
long long res, A[3][110000], t[3];

void next (int i)
{
  c[i]++;
  if (c[i]==k[i])
    c[i]=0;
}

int main() {
  int i, j;
  long long f, s;
  //freopen(taskname".in", "r", stdin);
 // freopen(taskname".out", "w", stdout);
  for (i=0; i<3; i++)
    scanf("%d", &k[i]);
  for (i=0; i<3; i++)
    scanf("%I64d", &t[i]);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%I64d", &s);
    f=s;
    for (j=0; j<3; j++)
    {
      f=t[j]+max(f,A[j][c[j]]);
      A[j][c[j]]=f;
      next(j);
    }
    res=max(res,f-s);
  }
  printf("%I64d\n", res);
  return 0;
}