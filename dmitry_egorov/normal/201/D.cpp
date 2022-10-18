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
#define maxp (239017ll)

using namespace std;

long long Deg[510000];
char s[510000];
int n, e, R[20], N[20];
int Q[510000];
int D[510000][15];
long long A[20];

long long gethash()
{
  long long ret=0ll;
  int i, len=strlen(s);
  for (i=0; i<len; i++)
    ret+=Deg[i]*((long long)s[i]);
  return ret;
}

int gen (int v, int ci, int cr)
{
  //cerr<<"!!!!!!!!!!!!!!!!!!!!     "<<v<<" "<<ci<<" "<<cr<<endl;
  if (ci>=cr)
    return cr;
  if (v==n)
    return ci;
  int cv=0, inv=v, lp=0;
  while (cv!=-1)
  {
  //  cerr<<cv<<" "<<lp<<" "<<R[cv]<<"       "<<v<<endl;
    if (D[lp][v]<R[cv])
    {
      v++;
      //cerr<<"???    "<<D[lp][v-1]<<endl;
      N[v]=N[cv], R[v]=R[cv], R[cv]=D[lp][v-1], N[cv]=v;
      cr=gen(v,ci+inv,cr);  
      N[cv]=N[v], R[cv]=R[v];
      v--;
      if (ci>=cr)
        return cr;

    }
    lp=R[cv], cv=N[cv], inv--;
  }

  return cr;
}

int main()
{
  long long tmp;
  int i, j, m, q, itmp, id, p=0, res=-1, tst=0;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  for (Deg[0]=1ll, i=1; i<51000; i++)
    Deg[i]=Deg[i-1]*maxp;
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf(" %s", s), A[i]=gethash();
  scanf("%d", &m);
  while (m>0)
  {
    m--, scanf("%d", &q), tst++;
    //cerr<<tst<<endl;
    for (e=0, i=0; i<q; i++)
    {
      scanf(" %s", s), tmp=gethash();
      for (id=-1, j=0; j<n; j++)
        if (A[j]==tmp)
          id=j;
      if (id!=-1)
        Q[e++]=id;
    }
    for (i=0; i<n; i++)
      D[e][i]=e;
    for (i=e-1; i>=0; i--)
    {
      for (j=0; j<n; j++)
        D[i][j]=D[i+1][j];
      D[i][Q[i]]=i;
    }
    R[0]=e, N[0]=-1;
   /* for (i=0; i<e; i++)
    {
      for (j=0; j<n; j++)
        cerr<<D[i][j]<<" ";
      cerr<<endl;
    }    */
    itmp=gen(0,0,(n*(n-1))/2+1);
    if (p<(n*(n-1))/2-itmp+1)
      p=(n*(n-1))/2-itmp+1, res=tst;
   // cerr<<"!@#ERTYUIKJHFGDS"<<endl;
  }
  if (p==0)
  {
    puts("Brand new problem!");
    return 0;
  }
  printf("%d\n[:", res); 
  for (i=0; i<p; i++)
    printf("|");
  printf(":]\n");
  return 0;
}