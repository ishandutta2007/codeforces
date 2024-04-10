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

int n;
//vector <int> Pr;
int D[110000], a, e, C[110000], res=1;

int main()
{
  int i, j, tmp, a;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  /*for (i=2; i<110000; i++)
    if (!u[i])
    {
      Pr.pb(i);
      if (i<2000)
        for (j=i*i; j<110000; j+=i)
          u[j]=1;
    }
  cerr<<Pr.size()<<endl;       */
  for (scanf("%d", &n), i=0; i<n; i++)
  {
    scanf("%d", &a);
    for (e=0, j=2; j*j<=a; j++)
      if (a%j==0)
      {
        C[e++]=j;
        while (a%j==0)
          a/=j;
      }
    if (a>1)
      C[e++]=a;
    for (tmp=0, j=0; j<e; j++)
      tmp=max(tmp,D[C[j]]);
    for (j=0; j<e; j++)
      D[C[j]]=max(D[C[j]],tmp+1);
  }
  for (i=0; i<110000; i++)
    res=max(res,D[i]);
  cout<<res<<endl;
  return 0;
}