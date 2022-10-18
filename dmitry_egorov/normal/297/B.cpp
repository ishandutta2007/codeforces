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

int sum;
map <int, int> A;
map <int, int> :: iterator it;

int main()
{
  int n, m, k, x, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (i=0; i<n; i++)
    scanf("%d", &x), A[-x]++;
  for (i=0; i<m; i++)
    scanf("%d", &x), A[-x]--;
  for (it=A.begin(); it!=A.end(); it++)
  {
    sum+=it->second;
    if (sum>0)
    {         
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}