#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#define ln log

using namespace std;

long long P[11], Res[1010][15];

long long deg (long long a, int i)
{
  int j;
  long long ans;
  ans=1;
  for (j=0; j<i; j++)
    ans*=a;
  return ans;
}  


void solve (int a, int minp)
{
  int i;
  //printf("solve(%d,%d)\n", a, minp);
  if (((double)(a-1))*ln(P[minp])<ln(1e18)+ln(2.0))
    Res[a][minp]=deg(P[minp],a-1);
  for (i=2; i<a; i++)
  {
    if (a%i==0)
    {
      if (Res[i][minp+1]==0)
        solve (i,minp+1);
      if (Res[i][minp+1]>0)
      {
       // printf("%I64d\n", Res[i][minp+1]);
        if (Res[a][minp]==0 && ln(Res[i][minp+1])+(((double)(a/i))-1.0)*ln(P[minp])<ln(1e18)+ln(2.0))
          Res[a][minp]=Res[i][minp+1]*deg(P[minp],a/i-1);
        if (Res[a][minp]>0 && ln(Res[i][minp+1])+(((double)(a/i))-1.0)*ln(P[minp])<ln(Res[a][minp]))
          Res[a][minp]=Res[i][minp+1]*deg(P[minp],a/i-1);
        //printf("OK");
      }
    }
  }
  //printf("solve(%d,%d)=%I64d\n", a, minp, Res[a][minp]);
}

int main()
{
  int n, i;
  //freopen(".out", "w", stdout);
  P[0]=2;
  P[1]=3;
  P[2]=5;
  P[3]=7;
  P[4]=11;
  P[5]=13;
  P[6]=17;
  P[7]=19;
  P[8]=23;
  P[9]=29;
  P[10]=31;
  for (i=0; i<11; i++)
    Res[1][i]=P[i];
  scanf("%d", &n);
  solve(n,0);
  printf("%I64d", Res[n][0]);
  return 0;
}