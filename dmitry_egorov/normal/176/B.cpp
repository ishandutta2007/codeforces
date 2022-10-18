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
#define mod (1000000007ll)
#define imod (1000000007)

using namespace std;

long long cnt;
int len, k;
char s1[1100], s2[1100];
bool C[1100];
int W[1100], sum;

int main()
{
  int i, j;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  gets(s1), gets(s2), len=strlen(s1);
  scanf("%d", &k);
  for (i=0; i<len; i++)
  {
    bool fl=1;
    for (j=0; j<len; j++)
      if (s1[(i+j)%len]!=s2[j])
        fl=0;
    if (fl)
      cnt++, C[i]=1;
  }
  if (k==0)
  {
    (C[0])?(puts("1")):(puts("0"));
    return 0;
  }
  long long ans=0ll;
  W[0]=1, sum=1;
  for (i=0; i<k-1; sum=(sum*1ll*(len-1))%mod, i++)
    for (j=0; j<len; j++)
    {
      W[j]=sum-W[j]+imod;
      if (W[j]>=imod)
        W[j]-=imod;
    }
  //cerr<<W[0]<<" "<<W[1]<<endl;
  for (ans=(sum*cnt)%mod, i=0; i<len; i++)
    if (C[i])
      ans+=mod-W[i], ans%=mod;
  printf("%I64d\n", ans);
  return 0;
}