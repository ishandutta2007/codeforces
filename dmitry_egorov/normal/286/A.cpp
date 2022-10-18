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

int P[110000];

int main()
{
  int i, n;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  if (n%4==2 || n%4==3)
  {
    puts("-1");
    return 0;
  }
  if (n%2==1)
  {
    P[n/2]=n/2;
  }
  for (i=0; i<n/2; i+=2)
    P[i]=i+1, P[i+1]=n-i-1, P[n-i-1]=n-i-2, P[n-i-2]=i;
  for (i=0; i<n; i++)
    printf("%d ", P[i]+1);
  printf("\n");
 /* for (i=0; i<n; i++)
    cerr<<P[P[i]]<<" ";
  cerr<<endl; */
  return 0;
}