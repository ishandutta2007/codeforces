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
#define mod (1000000007)

using namespace std;
                                
long long calc (long long d, long long k)
{           
  long long ret=1;
  while (k>0)
    k--, ret*=d, ret%=mod, d--;
  return ret;
}

long long res, S[12][12][12], D[12];
int Deg[12], Z[12], Y[12], C[15][15];

void add (int id, int v)
{
  D[id]+=v, D[id]%=mod;
}

int main()
{
  int i, n, j, k, t, cb, cc;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (Deg[0]=1, i=1; i<=9; i++)
    Deg[i]=Deg[i-1]*10;
  cin>>n, n++;
  for (i=0; i<10; i++)
    Z[i]=(n/Deg[i])%10;
  for (i=0; i<12; i++)
    for (C[i][0]=1, j=1; j<=i; j++)
      C[i][j]=C[i-1][j-1]+C[i-1][j];
  for (i=1; i<10; Y[i]+=Y[i-1], i++)
    if (i!=5 && i!=8)
      Y[i]++;
  for (cb=0, i=9; i>=0; i--)
  {
    cc=0;
    if (Z[i]>=5)
      cc++;
    if (Z[i]>=8)
      cc++;
    for (j=0; j<=i; j++)
      add(j+cb,Y[Z[i]]*C[i][j]*(1<<(3*i-2*j))), add(j+cb+1,cc*C[i][j]*(1<<(3*i-2*j)));
    if (Z[i]==4 || Z[i]==7)
      cb++;
  }
  D[0]--;
  int tmp2=0;
  for (i=0; i<10; i++)
  {          
    tmp2+=D[i];
    cerr<<i<<" "<<D[i]<<endl;
  }
  assert(tmp2==n-1);
  for (S[0][0][0]=1, i=0; i<10; i++)
    for (j=0; j<10; j++)
      for (k=0; k<=6; k++)
        for (t=0; t+k<=6 && j+t*i<10; t++)
          S[i+1][j+t*i][t+k]+=((S[i][j][k]*calc(D[i],t))%mod)*C[6-k][t], S[i+1][j+t*i][t+k]%=mod; 
  for (i=1; i<=9; i++)
    for (j=0; j<i; j++)
    {
      res+=D[i]*S[10][j][6];
      //cerr<<i<<" "<<j<<" "<<D[i]<<" "<<S[10][j][6]<<endl;
      res%=mod;
    }
  cout<<res<<endl;
  return 0;
}