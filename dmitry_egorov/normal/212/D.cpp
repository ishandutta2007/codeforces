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
#define maxn 1100000

using namespace std;

long long V[maxn];
long double Res[maxn];
int A[maxn], St[2][maxn], P[2][maxn], e[2]={1,1};
int D[2][maxn], n;

int main()
{
  int i, j, it, l, r, tmp, q;
  long long cc, cv;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d", &A[i]);
  for (i=0; i<2; i++, reverse(A,A+n))
    for (j=0; j<n; j++)
    { 
     // cerr<<i<<" "<<j<<" "<<e[i]<<" "<<St[i][e[i]-1]<<" "<<P[i][e[i]-1]<<endl;
      while (St[i][e[i]-1]>A[j])
        e[i]--;
      if (i==0)
        it=lower_bound(St[i],St[i]+e[i],A[j])-St[i];
      else
        it=lower_bound(St[i],St[i]+e[i],A[j]+1)-St[i];
      it--, St[i][e[i]]=A[j], P[i][e[i]++]=j+1;
     // cerr<<it<<"       "<<St[i][it]<<"   "<<P[i][it]<<"    "<<j+1<<endl;
      D[i][j]=j-P[i][it];
    }
  reverse(D[1],D[1]+n);
  for (i=0; i<n; i++)
  {
    l=min(D[0][i],D[1][i]), r=max(D[0][i],D[1][i]);
    //cerr<<l<<" "<<r<<endl;
    //cerr<<i<<"      "<<D[0][i]<<" "<<D[1][i]<<endl;
    V[1]+=A[i], V[l+2]-=A[i], V[r+2]-=A[i], V[l+r+3]+=A[i];
  }
  for (cv=V[1], cc=V[1], i=1; i<=n; i++, cc+=V[i], cv+=cc)
    Res[i]=((long double)cv)/((long double)(n-i+1));
  for (scanf("%d", &q); q>0; q--)
    scanf("%d", &tmp), printf("%.10lf\n", (double)Res[tmp]);
  return 0;
}