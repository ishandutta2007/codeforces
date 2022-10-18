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

int n, A[(1<<18)+100];
int L[110000], X[110000], B[110000], e, cr;
map <int, int> XX;
long long ans, k, ck;

int sum (int l, int r)
{
  int res=0;
  l+=(1<<17), r+=(1<<17);
  //cerr<<"      !!!!!!!!!!!    "<<A[(1<<17)]<<" "<<A[(1<<17)+2]<<" "<<A[(1<<16)]<<"        "<<A[(1<<16)+1]<<endl;
  //cerr<<l<<" "<<r<<"        "<<res<<endl;
  while (r-l>0)
  {
    //cerr<<l<<" "<<r<<"           "<<A[l]<<endl;
    if (l&1)
      res+=A[l], l++;
    if (r&1)
      r--, res+=A[r];
    l/=2, r/=2;
  }
  //cerr<<l<<" "<<r<<"        "<<res<<endl;
  return res;
}

void add (int v, int s)
{
  v+=(1<<17);
  //cerr<<v<<"               "<<s<<endl;
  while (v>0)
    A[v]+=s, v/=2;
}

int main()
{
  int i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%I64d", &n,  &k), k=-k;
  ans=((n)*1ll*(n-1))/2ll;
  for (i=0; i<n; i++)
    scanf("%d", &B[i]), X[i]=B[i];
  sort(X,X+n);
  e=unique(X,X+n)-X;
  for (i=0; i<e; i++)
    XX[X[i]]=i;
  for (i=0; i<n; i++)
    B[i]=XX[B[i]];
  for (i=0; i<n; i++)
    L[i]=sum(B[i]+1,e), k+=L[i], add(B[i],1);// cerr<<i<<"       "<<L[i]<<"        "<<B[i]<<"              "<<e<<endl;
  memset(A,0,sizeof(A));
  for (i=n-1; i>=0; i--)
    L[i]+=sum(0,B[i]), add(B[i],1);// cerr<<i<<" "<<L[i]<<endl;
  if (k<=0)
  {
    printf("%I64d", ans);
    return 0;
  }
  ans=0;
  memset(A,0,sizeof(A));
  for (i=0; i<n; i++)
  {
    while (cr<n && ck<k)
      ck+=L[cr]-sum(B[cr]+1,e), add(B[cr],1), cr++;
    if (cr==n && ck<k)
      break;
    //cerr<<cr<<"           "<<ck<<"      "<<k<<endl;
    if (i!=0)
      ans+=max(n-cr,0);
    ck-=L[i]-sum(0,B[i]), add(B[i],-1);
    //cr=max(cr,i);
  }
  printf("%I64d", ans);
  return 0;
}