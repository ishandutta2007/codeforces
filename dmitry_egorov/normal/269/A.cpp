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

int res;

int cnt (int x)
{
  int ret=0;
  while ((1<<(2*ret))<x)
    ret++;
  return ret;
}

int main()
{
  int i, n, x, y;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d%d", &x, &y), res=max(res,max(cnt(y),1)+x);
  cout<<res<<endl;
  return 0;
}