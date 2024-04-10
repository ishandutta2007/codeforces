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

const int lcm=8*9*5*7*11*13;
long long D[lcm];
long long res;

int main()
{
  long long a, b, c, d;
  int k, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  cin>>b>>a>>k;
  memset(D,-1,sizeof(D)), D[b%lcm]=0;
  while (b>a)
  {
    for (d=1ll, i=2; i<=k; i++)
      if (b%i<=b-a)
        d=max(d,b%i);
    b-=d, res++;
    if (b-a>3ll*lcm)
    {
      if (D[b%lcm]==-1)
        D[b%lcm]=res;
      else
      {
        c=((b-a)/lcm)-1ll;
        res+=c*(res-D[b%lcm]);
        b-=c*lcm;
      }
    }
  }
  cout<<res<<endl;
  return 0;
}