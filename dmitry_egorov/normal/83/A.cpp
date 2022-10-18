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
#define inf (((int)1e9)+5)
#define pb push_back

using namespace std;

int A[110000];

int main() {
  int i, n, c;
  long long res=0;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  A[n]=inf;
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=1, c=1; i<=n; i++) 
  {
    if (A[i]!=A[i-1])
      res+=((long long)(c+1))*((long long)c)/((long long)2), c=1;
    else
      c++;
  }
  printf("%I64d\n", res);
  return 0;
}