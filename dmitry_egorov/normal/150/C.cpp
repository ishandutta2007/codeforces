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

struct node
{
  long long b, p, s, sum;
  node ()
  {
    b=0, p=0, s=0, sum=0;
  }
  node (long long _b, long long _p, long long _s, long long _sum)
  {
    b=_b, p=_p, s=_s, sum=_sum;
  }
  void out ()
  {
    cerr<<b<<"  !!  "<<p<<" "<<s<<" "<<sum<<endl;
  }
}A[(1<<19)+200];

long long P[210000], X[210000], S[210000];

node merge (node l, node r)
{
  node res;
  res.b=max(max(l.b,r.b),l.s+r.p);
  res.p=max(l.p,l.sum+r.p);
  res.s=max(r.s,l.s+r.sum);
  res.sum=l.sum+r.sum;
  return res;
}

node get (int l, int r)
{
  //cerr<<l<<"      "<<r<<endl;
  node ln=node(0,0,0,0), rn=node(0,0,0,0);
  l+=(1<<18), r+=(1<<18);
  while (l<r)
  {
    if (l&1)
      ln=merge(ln,A[l]), l++;
    if (r&1)
      r--, rn=merge(A[r],rn);
    l/=2, r/=2;
  }
  //(merge(ln,rn)).out();
  return (merge(ln,rn));
}

int main()
{
  long long tmp, c, res=0ll;
  int i, x, a, b, n, m;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%I64d", &n, &m, &c);
  for (i=0; i<n; i++)
    scanf("%d", &x), X[i]=x;
  for (i=1; i<n; i++)
    scanf("%d", &x), P[i]=x;
  for (i=1; i<n; i++)
    S[i]=S[i-1]+50ll*(X[i]-X[i-1])-c*P[i];// cerr<<i<<" "<<S[i]<<endl;
  for (i=1; i<n; i++)
    tmp=max(50ll*(X[i]-X[i-1])-P[i]*c,0ll), A[i+(1<<18)]=node(tmp,tmp,tmp,50ll*(X[i]-X[i-1])-P[i]*c);
  for (i=(1<<18)-1; i>0; i--)
    A[i]=merge(A[2*i],A[2*i+1]);
  for (i=0; i<m; i++)
  {
    scanf("%d%d", &a, &b);
    res+=(get(a,b)).b;
    //cerr<<res<<endl;
  }
  printf("%.8lf\n", ((double)res)/100.0);
  return 0;
}