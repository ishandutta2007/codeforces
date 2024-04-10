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

int n, m;
long double P[3100][310];
long double E[310][3100], S[310];
long double T[3100];
long double sum;

int main()
{
  int i, j, id, tmp;
  long double cv;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (i=0; i<n; i++)
    for (j=0; j<m; j++)
      scanf("%d", &tmp), P[i][j]=((long double)tmp)/1000.0;
  for (i=0; i<m; i++)
  {
    E[i][0]=1.0;
    for (cv=E[i][0], j=1; j<=n; j++)
      S[i]+=cv*P[j-1][i], cv*=(1.0-P[j-1][i]), cv+=E[i][j];
    //cerr<<i<<" "<<S[i]<<endl;
  }
  //cerr<<n<<endl;
  for (int ii=0; ii<n; ii++)
  {
    id=0;
    for (j=1; j<m; j++)
      if (S[id]<S[j])
        id=j;
    //cerr<<id<<" "<<S[id]<<endl;
    sum+=S[id], memcpy(T,E[id],sizeof(T)), S[id]=0.0;
    cv=E[id][0], E[id][0]=0.0;
    for (j=1; j<=n; j++)
      E[id][j]=cv*P[j-1][id], cv*=(1.0-P[j-1][id]), cv+=T[j];
    for (cv=E[id][0], j=1; j<=n; j++)
      S[id]+=cv*P[j-1][id], cv*=(1.0-P[j-1][id]), cv+=E[id][j];
  } 
  printf("%.12lf\n", (double)sum);
  return 0;
}