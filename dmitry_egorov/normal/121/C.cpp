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

int e, res, n;
long long Deg[15], k;
int A[5000];

bool isluck (int a)
{
  while (a>0)
  {
    if (a%10!=4 && a%10!=7)
      return 0;
    a/=10;
  }
  return 1;
}

void gen (int p, vector <int> v)
{
  //cerr<<p<<" "<<v.size()<<endl;
  if (v.size()==0)
    return;
  long long f=1ll;
  int i;
  for (i=2; i<(int)v.size(); i++)
    f*=((long long)i);
  i=0;
  while (k>f)
    k-=f, i++;
  if (isluck(p+1) && isluck(v[i]))
    res++;
  v.erase(v.begin()+i);
  gen(p+1,v);
}

int main()
{
  int i, j, kk, cnt;
  long long c;
  vector <int> tmp;
  tmp.clear();
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (Deg[0]=1ll, i=1; i<15; i++)
    Deg[i]=Deg[i-1]*(10ll);
  for (i=1; i<=9; i++)
    for (j=0; j<(1<<i); j++, e++)
      for (kk=0; kk<i; kk++)
      {
        A[e]+=4*Deg[kk];
        if (j&(1<<kk))
          A[e]+=3*Deg[kk];
      }
  sort(A,A+e);
  scanf("%d%I64d", &n, &k);
  cnt=1, c=1;
  while (c<k) 
    cnt++, c*=((long long)cnt);
  if (cnt>n)
  {
    puts("-1");
    return 0;
  }
  for (i=0; i<e; i++)
    if (A[i]<=n-cnt)
      res++;
  for (i=0; i<cnt; i++)
    tmp.pb(n-i);
  sort(tmp.begin(),tmp.end());
  gen(n-cnt,tmp);
  printf("%d\n", res);
  return 0;
}