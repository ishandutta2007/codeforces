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

char s[1100000];

struct tree 
{
  bool inv;
  int A[2][2];
  void norm ()
  {
    if (inv)
    {
      inv=0, swap(A[0][0],A[1][1]), swap(A[0][1],A[1][0]);
    }
  }
  void merge (tree ll, tree rr)
  {
    tree l=ll, r=rr;
    l.norm(), r.norm();
    inv=0;
    A[0][0]=l.A[0][0]+r.A[0][0], A[1][1]=l.A[1][1]+r.A[1][1];
    A[0][1]=max(l.A[0][0]+r.A[0][1],l.A[0][1]+r.A[1][1]);
    A[1][0]=max(l.A[1][1]+r.A[1][0],l.A[1][0]+r.A[0][0]);
  }
  void conv (char s)
  {
    inv=0;
    if (s=='4')
      A[0][0]=1, A[0][1]=0, A[1][0]=1, A[1][1]=0;
    else    
      A[0][0]=0, A[0][1]=1, A[1][0]=0, A[1][1]=1;
  }
};

tree A[(1<<21)+100];
bool P[(1<<21)+100];
int n, m;

void push (int v)
{
  if (!P[v])
    return;
  P[v]=0, A[v].inv=(!A[v].inv);
  if (v<(1<<20))
    P[2*v]^=1, P[2*v+1]^=1;
}

void inv (int v, int L, int R, int l, int r)
{
  push(v);
  if (L>=l && R<=r)
  {
    A[v].inv=(!A[v].inv);
    if (v<(1<<20))
      P[2*v]^=1, P[2*v+1]^=1;
    return;
  }
  if (L>=r || R<=l)
    return;
  inv(2*v,L,(L+R)/2,l,r);
  inv(2*v+1,(L+R)/2,R,l,r);
  A[v].merge(A[2*v],A[2*v+1]);
}

int main()
{
  int i, l, r;
  char str[20];
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d ", &n, &m);
  gets(s);
  for (i=0; i<n; i++)
    A[i+(1<<20)].conv(s[i]);
  for (i=(1<<20)-1; i>0; i--)
    A[i].merge(A[2*i],A[2*i+1]);
  //cerr<<A[1].A[0][0]<<" "<<A[1].A[0][1]<<" "<<A[1].A[1][0]<<" "<<A[1].A[1][1]<<endl;
  while (m>0)
  {
    m--, scanf(" %s", str);
    if (str[0]=='c')
    {
      printf("%d\n", max(A[1].A[0][0],A[1].A[0][1]));
      continue;
    }
    scanf("%d%d ", &l, &r), l--;
    inv(1,0,(1<<20),l,r);
  }
  return 0;
}