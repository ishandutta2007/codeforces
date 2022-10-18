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

map <int, int> M;

int main()
{
  int i, n, x, res=0;
  map <int, int> :: iterator it;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &x);
    if (x>0) 
      M[x]++;
  }
  for (it=M.begin(); it!=M.end(); it++)
  {
    if (it->second>2)
    {
      puts("-1");
      return 0;
    }
    res+=(it->second==2);
  }
  printf("%d\n", res);
  return 0;
}