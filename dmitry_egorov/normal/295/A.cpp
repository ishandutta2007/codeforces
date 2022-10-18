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

#define maxn (110000)

int A[maxn], L[maxn], R[maxn], D[maxn];
long long Z[maxn], P[maxn], Ans[maxn];

int main()
{
  int i, n, k, m, x, y;
  long long c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=0; i<m; i++)
    scanf("%d%d%d", &L[i], &R[i], &D[i]), L[i]--, R[i]--;
  for (i=0; i<k; i++)
    scanf("%d%d", &x, &y), x--, y--, P[x]++, P[y+1]--;
  for (c=0, i=0; i<m; i++)
    c+=P[i], Z[L[i]]+=c*1ll*D[i], Z[R[i]+1]-=c*1ll*D[i];
  c+=P[m], assert(c==0);
  for (c=0, i=0; i<n; i++)
    c+=Z[i], Ans[i]=A[i]+c;
  c+=Z[n], assert(c==0);
  for (i=0; i<n; i++)
    printf("%I64d ", Ans[i]);
  printf("\n"); 
  return 0;
}