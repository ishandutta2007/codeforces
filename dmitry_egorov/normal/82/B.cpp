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

int n, e;
vector <int> res[300], A[300];
bool u[300], fl;

int main() {
  int i, j, k, tmp, c;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<(n*(n-1))/2; i++)
  {
    scanf("%d", &tmp);
    for (j=0; j<tmp; j++)
      scanf("%d", &c), A[c].pb(i);
  }
  for (i=0; i<300; i++)
    sort(A[i].begin(),A[i].end());
  for (i=0; i<300; i++)
    if (!u[i] && A[i].size()!=0)
    {
      u[i]=1;
      res[e].pb(i);
      for (j=i+1; j<300; j++)
        if (!u[j] && A[i].size()==A[j].size())
        {
          fl=1;
          for (k=0; k<(int)A[i].size(); k++)
            if (A[i][k]!=A[j][k])
              fl=0;
          if (fl)
            u[j]=1, res[e].pb(j);
        }
      e++;
    }
  if (n==2)
  {
    printf("1 %d\n", res[0][0]);
    printf("%d", res[0].size()-1);
    for (i=1; i<(int)res[0].size(); i++)
      printf(" %d", res[0][i]);
    printf("\n");
    return 0;
  }
  for (i=0; i<n; i++)
  {
    printf("%d", res[i].size());
    for (j=0; j<(int)res[i].size(); j++)
      printf(" %d", res[i][j]);
    printf("\n");
  }
  return 0;
}