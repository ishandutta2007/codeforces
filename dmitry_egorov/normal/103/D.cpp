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

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back
#define mp make_pair

using namespace std;

vector<vector<vector<long long> > > S;  
vector<vector<long long> > tmp;
vector<long long> tmp2;
long long A[300000];

long long solve (int a, int b)
{
  //cerr<<a<<" "<<b<<endl;
  int c=(a/b)%300;
  long long res=0ll;
  while (c>=0)
    res+=A[a], a-=b, c--;
    //cerr<<res<<endl;
  if (a>=0)
    res+=S[b][a%b][((a/b)/300)];
  //cerr<<a<<" EWREJYU "<<b<<" "<<res<<endl;
  return res;
}

int main()
{
  int n, t, i, j, k, a, b, c, st;
  long long sum;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]);
  S.pb(tmp);
  for (i=1; i<500; i++)
  {
    tmp.clear();
    for (j=0; j<i; j++)
    {
      tmp2.clear();
      for (st=j, k=0, sum=0ll; st<300000; sum+=A[st], st+=i, k++)
        if (k==300)
          tmp2.pb(sum), k=0;
      tmp.pb(tmp2);
    }
    S.pb(tmp);
    //cerr<<i<<endl;
  }
  //cerr<<endl<<endl<<S[1][0][995]<<endl;
  for (scanf("%d", &t); t>0; t--)
  {
    //cerr<<"!!!!!  "<<t<<endl;
    scanf("%d%d", &a, &b);
    a--;
    sum=0ll;
    if (b>=500)
    {
      while (a<300000)
        sum+=A[a], a+=b;
      printf("%I64d\n", sum);
      continue;
    }
    c=(299999/b)*b+(a%b);
    if (c>=300000)
      c-=b;
    printf("%I64d\n", solve(c,b)-solve(a,b)+A[a]);
  }
  return 0;
}