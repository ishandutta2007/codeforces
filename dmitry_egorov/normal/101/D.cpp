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

int Head[110000], Dest[210000], Tin[110000], Tout[110000], Next[210000], e, L[210000];
int CTime, Prev[110000], n;
bool u[110000];
long long D[110000], W[110000], Tw[110000];
long long Lp[110000];

bool check (int i, int j)
{
  return W[i]*(Tw[j]+2ll*Lp[j])>W[j]*(Tw[i]+2ll*Lp[i]);
}

void add (int v1, int v2, int l)
{
  //cerr<<v1<<" "<<v2<<" "<<l<<endl;
  Dest[e]=v2, L[e]=l;
  Next[e]=Head[v1];
  Head[v1]=e;
  e++;
}

void dfs (int v)
{
  Tin[v]=CTime, CTime++;
  u[v]=1;
  for (int r=Head[v]; r!=-1; r=Next[r])
    if (!u[Dest[r]])
      Prev[Dest[r]]=v, Lp[Dest[r]]=L[r], dfs(Dest[r]);
  Tout[v]=CTime, W[v]=Tout[v]-Tin[v];
}

void solve (int v)
{
  //cerr<<v<<" "<<Prev[v]<<endl;
  vector <int> tmp;
  tmp.clear();
  int r;
  //long long t=0ll;
  for (r=Head[v]; r!=-1; r=Next[r])
    if (Prev[Dest[r]]==v)
    {
      solve(Dest[r]);
      tmp.pb(Dest[r]);
    } 
  sort(tmp.begin(),tmp.end(),check);
  for (r=0; r<(int)tmp.size(); r++)
    D[v]+=D[tmp[r]]+W[tmp[r]]*(Tw[v]+Lp[tmp[r]]), Tw[v]+=Tw[tmp[r]]+2ll*Lp[tmp[r]];
}

int main()
{
  int i, v1, v2, l;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  memset(Head,-1,sizeof(Head));
  scanf("%d", &n);
  for (i=0; i<n-1; i++)
    scanf("%d%d%d", &v1, &v2, &l), v1--, v2--, add(v1,v2,l), add(v2,v1,l);
  dfs(0);
  solve(0);
  printf("%.8lf\n", (double)(((long double)D[0])/((long double)(n-1))));
  return 0;
}