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
#include <utility>

#define taskname ""
#define inf ((int)1e9)
#define pb push_back

using namespace std;

int P[40000], e;
int N[100000];
bool u[100000];

int solve (int a, int b, int k)
{
  //cerr<<a<<" "<<b<<" "<<k<<endl;
  int i;
  if (b<P[k])
    return 0;
  if ((b/P[k])<P[k])
    return ((int)(a<=P[k]));
  a=(a+P[k]-1)/P[k], b/=P[k];
  if (a>b)
    return 0;
  int ans=b-a+1;
  for (i=0; i<k && P[i]<=b; i++)
    if (i!=k)
      ans-=solve(a,b,i);
  //cerr<<a<<" "<<b<<" "<<k<<" "<<ans<<endl;
  return ans;
}

int main() {
  int i, j, a, b, k;
  //freopen(taskname".in", "r", stdin);
  //freopen(taskname".out", "w", stdout);
  u[0]=1, u[1]=1;
  for (i=2; i<100000; i++)
    if (!u[i])
    {
      N[i]=e, P[e]=i, e++;
      if (i<2000)
        for (j=i*i; j<100000; j+=i)
          u[j]=1;
    }
  scanf("%d%d%d", &a, &b, &k);
  if (k>=100000)
  {
    for (i=0; i<e; i++)
      if (k%P[i]==0)
      {
        printf("0\n");
        return 0;
      }
    if (a<=k && b>=k)
      printf("1\n");
    else
      printf("0\n");
    return 0;
  }
  if (u[k])
  {
    printf("0\n");
    return 0;
  }
  printf("%d\n", solve(a,b,N[k]));
  return 0;
}