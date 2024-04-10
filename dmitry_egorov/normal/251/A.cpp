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

int A[110000];
long long res;

int main()
{
  int n, d, i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &d);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  A[n]=2*inf+10;
  for (i=0, j=0; i<n; i++)      
  {
    while (A[j]<=A[i]+d)
      j++;
    res+=(j-i-1)*1ll*(j-i-2);
  }
  res/=2;
  cout<<res<<endl;
  return 0;
}