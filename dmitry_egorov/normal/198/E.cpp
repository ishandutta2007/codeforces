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
#define linf ((long long)2e18)
#define pb push_back
#define mp make_pair

using namespace std;

int res;
map <int, int> MtoM;
int M[251000], em;
long long D[251000], R[251000];
int Mg[251000], P[251000];
vector <int> Id[251000];
int Cid[251000];
int bq, eq=1, Q[251000], n;
long long T[(1<<19)+200];

int conv (int cp)
{
  int l=-1, r=em;
  while (r-l>1)
    (M[(r+l)/2]<=cp)?(l=(l+r)/2):(r=(l+r)/2);
  //cerr<<cp<<" "<<l<<endl;
  return l+1;
}

bool cmp (int a, int b)
{
  if (D[a]!=D[b])
    return D[a]<D[b];
  return a<b;
}

void addt (int v, int l, int r, int L, int RR, long long rd)
{
  if (T[v]>rd || l>=RR || r<=L)
    return;
  if (v>=(1<<18))
  {
    int vv=v-(1<<18);
    while (T[v]<=rd)
      res++, Q[eq++]=Id[vv][Cid[vv]], Cid[vv]++, T[v]=D[Id[vv][Cid[vv]]];// cerr<<eq-1<<" "<<Q[eq-1]<<endl;  
    return;
  }
  addt(2*v,l,(l+r)/2,L,RR,rd);
  addt(2*v+1,(l+r)/2,r,L,RR,rd);
  T[v]=min(T[2*v],T[2*v+1]);
}

void add (int id)
{
  //cerr<<id<<" "<<P[id]<<" "<<R[id]<<endl;
  addt(1,0,(1<<18),0,P[id],R[id]);
}

void tr ()
{
  printf("%I64d\n", T[1]);
  for (int i=0; i<4; i++, printf("\n"))
    for (int j=0; j<(1<<i); j++)
      printf("%I64d ", T[(1<<(15+i))+j]);
  printf("\n\n");
} 

int main()
{
  int x, y, _x, _y, p, _r, i;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%d%d%d%d%d", &x, &y, &p, &_r, &n), P[n]=p, R[n]=_r*1ll*_r;
  for (i=0; i<n; i++)
    scanf("%d%d%d%d%d", &_x, &_y, &Mg[i], &P[i], &_r), R[i]=_r*1ll*_r, D[i]=((x-_x)*1ll*(x-_x))+((y-_y)*1ll*(y-_y)), M[em++]=Mg[i];
  sort(M,M+em), em=unique(M,M+em)-M, M[em]=inf+10;
  //cerr<<em<<endl;
  for (i=0; i<em; i++)
    MtoM[M[i]]=i;// cerr<<M[i]<<" ";
  //cerr<<endl;
  for (P[n]=conv(P[n]), i=0; i<n; i++)
    P[i]=conv(P[i]), Id[MtoM[Mg[i]]].pb(i);
  //for (i=0; i<=n; i++)
  //  cerr<<MtoM[Mg[i]]<<" "<<P[i]<<" "<<R[i]<<endl;
  D[n+1]=linf;
  for (i=0; i<em; i++)
    sort(Id[i].begin(),Id[i].end(),cmp), Id[i].pb(n+1);
  for (i=0; i<(1<<19); i++)
    T[i]=linf;
  for (i=0; i<em; i++)
    /*cerr<<Id[i][0]<<" "<<D[Id[i][0]]<<endl,*/ T[i+(1<<18)]=D[Id[i][0]];
  for (i=(1<<18)-1; i>0; i--)
    T[i]=min(T[2*i],T[2*i+1]);
  Q[0]=n;
  while (bq<eq)
  {
    //tr();
    add(Q[bq]), bq++;
  }
  //tr();
  printf("%d\n", res);
  return 0;
}