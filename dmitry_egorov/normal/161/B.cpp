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

int n, k, E[2];
pair <long long, int> C[2][1100];
long long sum;
vector <int> ID[1100];

void print()
{
  int i, j;
  printf("%I64d.%I64d\n", sum/2ll, 5ll*(sum%2ll));
  for (i=0; i<k; i++)
  {
    printf("%d", ID[i].size());
    for (j=0; j<(int)ID[i].size(); j++)
      printf(" %d", ID[i][j]);
    printf("\n");
  }
  exit(0);
}

int main()
{
  int t, i;
  long long c;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &k);
  for (i=0; i<n; i++)
    scanf("%I64d%d", &c, &t), t--, C[t][E[t]++]=mp(c,i+1), sum+=c;
  sort(C[0],C[0]+E[0]);
  sort(C[1],C[1]+E[1]);
  sum*=2ll, C[0][E[0]].first=2ll*inf, C[1][E[1]].first=2ll*inf;
  if (E[0]==0)
  {
    for (i=0; i<E[0]; i++)
      ID[i%k].pb(C[0][i].second);
    for (i=0; i<E[1]; i++)
      ID[k-1-(i%k)].pb(C[1][i].second);
    print();
  }
  if (E[0]>=k)
  {
    for (i=0; i<=E[0]-k; i++)
      ID[0].pb(C[0][i].second);
    for (i=0; i<E[1]; i++)
      ID[0].pb(C[1][i].second);
    sum-=min(C[0][0].first,C[1][0].first);
    for (i=1; i<k; i++)
      sum-=C[0][E[0]-i].first, ID[i].pb(C[0][E[0]-i].second);
    print();
  }


    for (i=0; i<E[0]; i++)
      ID[i].pb(C[0][i].second);
    for (i=0; i<E[1]; i++)
      ID[E[0]+(i%(k-E[0]))].pb(C[1][i].second);


  for (i=0; i<E[0]; i++)
    sum-=C[0][i].first;
  print();
  return 0;
}