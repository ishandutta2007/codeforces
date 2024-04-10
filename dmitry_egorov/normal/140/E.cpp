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

int Wdc[5010][5010];
int Wfc[5010][5010];
int D[5010], sum, D2[5010], nsum, plen;
int n, m, p;
long long lp;

int mod (int v)
{
  if (v>=p)
    return v-p;
  else
    return v;
}

int main()
{
  int i, j, len;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &p), lp=p;

  Wdc[1][1]=1, Wfc[1][1]=m%p;
  for (i=2; i<=5000; i++)
    for (j=1; j<=i; j++)
      Wdc[i][j]=mod((int)((((long long)Wdc[i-1][j-1])*((long long)j))%lp)+(int)((((long long)Wdc[i-1][j])*((long long)(j-1)))%lp));

  for (i=2; i<=5000; i++)
    for (j=1; j<=i; j++)
      Wfc[i][j]=( ((((long long)Wfc[i-1][j-1])*((long long)(m-j+1)))) + ((((long long)Wfc[i-1][j])*((long long)(j-1))))  )%lp;
  sum=1, D[0]=1;
  /*cerr<<Wdc[1][1]<<" "<<Wdc[1][2]<<endl;
  cerr<<Wdc[2][1]<<" "<<Wdc[2][2]<<endl;
  cerr<<Wfc[1][1]<<" "<<Wfc[1][2]<<endl;
  cerr<<Wfc[2][1]<<" "<<Wfc[2][2]<<endl;  */   
  while (n>0)
  {
    n--, scanf("%d", &len);
    for (i=1; i<=len; i++)
      D2[i]=mod( (int)((((long long)sum)*Wfc[len][i])%lp) + p - (int)((((long long)D[i])*Wdc[len][i])%lp)), nsum=mod(nsum+D2[i]);
    for (i=0; i<=len; i++)
      D[i]=D2[i], D2[i]=0;
    for (i=len+1; i<=plen; i++)
      D[i]=0;
    sum=nsum, nsum=0, plen=len;
    //cerr<<D[0]<<" "<<D[1]<<" "<<D[2]<<" "<<sum<<endl;
  }  
  printf("%d\n", sum);
  return 0;
}