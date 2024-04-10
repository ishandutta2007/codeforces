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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

int e;
int Res[1100][3], Next[1100], V[1100], m, Prev[1100];

int main()
{
  int i, n, a, b, c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<m; i++)
    scanf("%d%d%d", &a, &b, &c), Next[a]=b, V[a]=c, Prev[b]=a;
  for (i=1; i<=n; i++)
    if (Next[i]!=0 && Prev[i]==0)
    {
      c=Next[i], Res[e][0]=i, Res[e][2]=V[i];
      while (Next[c]!=0)
        Res[e][2]=min(Res[e][2],V[c]), c=Next[c];
      Res[e][1]=c;
      e++;
    }
  printf("%d\n", e);
  for (i=0; i<e; i++)
    printf("%d %d %d\n", Res[i][0], Res[i][1], Res[i][2]);
  return 0;
}