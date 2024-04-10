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
  
bool u[210], A[210][210];
int C[210], T[210];

int main()
{
  bool fl;
  int n, res=inf, i, j, t, st;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &T[i]), T[i]--;
  for (i=0; i<n; i++)
    for (scanf("%d", &C[i]), j=0; j<C[i]; j++)
      scanf("%d", &t), A[t-1][i]=1; 
  for (st=0; st<3; st++)
  {
    int tres=n-1, cnt=n, p=st;
    memset(u,0,sizeof(u));
    while (cnt>0)
    {
      tres++, p=(p+1)%3;
      bool fl2=1;
      while (fl2)
        for (fl2=0, i=0; i<n; i++)
          if (T[i]==p && (!u[i]))
          {
            for (fl=1, j=0; j<n; j++)
              if ((!u[j]) && A[j][i])
                fl=0;
            if (fl)
              cnt--, u[i]=1, fl2=1;
          }
    }
//    cerr<<st<<" "<<tres<<endl;
    res=min(res,tres);
  }
  printf("%d\n", res);
  return 0;
}