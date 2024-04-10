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

long long D[1234567], res;

int main()
{
  int n, m, i, v1, v2;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d", &v1, &v2), v1--, v2--, D[v1]++, D[v2]++;
  for (i=0; i<n; i++)
    res+=D[i]*((long long)(n-1ll-D[i]));
  res/=2ll, res=((n*1ll*(n-1ll)*1ll*(n-2ll))/6ll)-res;
  printf("%I64d\n", res);
  return 0;
}