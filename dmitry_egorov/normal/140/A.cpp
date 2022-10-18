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

int main()
{
  int n;
  long double r, R;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>n>>R>>r;
  if (n==1)
  {
    if (r<=R)
      puts("YES");
    else
      puts("NO");
    return 0;
  }
  if (n==2)
  {
    if (2.0*r<=R)
      puts("YES");
    else
      puts("NO");
    return 0;
  }
  if (2.0*r>=R)
  {
    puts("NO");
    return 0;
  }
  if (2.0*((long double)n)*asin(r/(R-r))<=2.0*M_PI+1e-8)
    puts("YES");
  else
    puts("NO");
  return 0;
}