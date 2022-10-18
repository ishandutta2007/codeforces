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

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int n, k, A[110];

int main() {
  int i, res=0;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  while (A[0]!=k)
  {
    res++;
    for (i=0; i<n; i++)
      if (A[i]!=k && A[i]!=A[i+1])
        A[i]++;
  }
  printf("%d\n", res);
  return 0;
}