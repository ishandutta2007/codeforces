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

int A[(1<<18)+100][26], n, m, C[(1<<18)+100], L[(1<<18)+100], R[(1<<18)+100];
int Cnt[26], I[26], D[26];
char s[110000];

void push (int v)
{
  if (v>=(1<<17))
    return;
  if (C[v]==-1)
    return;
  int ls=2*v, rs=2*v+1, up=(R[v]-L[v])/2, i, add;
  if (C[v]==0)
    for (i=0; i<26; i++)
      add=min(up,A[v][i]), up-=add, A[ls][i]=add, A[rs][i]=A[v][i]-add;
  else
    for (i=0; i<26; i++)
      add=min(up,A[v][i]), up-=add, A[rs][i]=add, A[ls][i]=A[v][i]-add;
  C[ls]=C[v], C[rs]=C[v], C[v]=-1;
}

void calc (int v, int l, int r)
{
  if (l<=L[v] && R[v]<=r)
  {
    for (int i=0; i<26; i++)
      Cnt[i]+=A[v][i];
    return;
  }
  if (L[v]>=r || R[v]<=l)
    return;
  push(v), calc(2*v,l,r), calc(2*v+1,l,r);
}

void goI (int v, int l, int r)
{
  if (l<=L[v] && R[v]<=r)
  {
    C[v]=0;
    int up=R[v]-L[v], i, add;
    for (i=0; i<26; i++)
      add=min(up,I[i]), up-=add, A[v][i]=add, I[i]-=add;
    return;
  }
  if (L[v]>=r || R[v]<=l)
    return;
  push(v), goI(2*v,l,r), goI(2*v+1,l,r);
  for (int j=0; j<26; j++)
    A[v][j]=A[v<<1][j]+A[(v<<1)+1][j];
}

void goD (int v, int l, int r)
{
  //cerr<<v<<" "<<l<<" "<<r<<"       "<<D[0]<<D[1]<<"      "<<L[v]<<" "<<R[v]<<endl;
  if (l<=L[v] && R[v]<=r)
  {
    C[v]=1;
    int up=R[v]-L[v], i, add;
    for (i=25; i>=0; i--)
      add=min(up,D[i]), up-=add, A[v][i]=add, D[i]-=add;
    return;
  }
  if (L[v]>=r || R[v]<=l)
    return;
  push(v), goD(2*v,l,r), goD(2*v+1,l,r);
  for (int j=0; j<26; j++)
    A[v][j]=A[v<<1][j]+A[(v<<1)+1][j];
}

int main()
{
  int i, l, r, j, cnt;
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d%d ", &n, &m), gets(s);
  memset(C,-1,sizeof(C));
  for (i=0; i<n; i++)
    A[i+(1<<17)][(int)(s[i]-'a')]++;
  for (i=(1<<17); i<(1<<18); i++)
    L[i]=i-(1<<17), R[i]=i-(1<<17)+1;
  for (i=(1<<17)-1; i>0; i--)
    for (L[i]=L[2*i], R[i]=R[2*i+1], j=0; j<26; j++)
      A[i][j]=A[2*i][j]+A[2*i+1][j];
  for (i=0; i<m; i++)
  {
    scanf("%d%d", &l, &r), l--;
    memset(Cnt,0,sizeof(Cnt)), calc(1,l,r);
    for (j=0, cnt=0; j<26; j++)
      if (Cnt[j]&1) 
        cnt++;
    if (cnt>1 || (cnt==1 && (r-l)%2==0))
      continue;
    for (j=0; j<26; j++)
      I[j]=Cnt[j]/2, D[j]=Cnt[j]/2;
    goI(1,l,(l+r)/2), goD(1,(l+r+1)/2,r);
    if (cnt==1)
    {
      memset(I,0,sizeof(I));
      for (j=0; j<26; j++)
        if (Cnt[j]&1)
          I[j]=1;
      //cerr<<I[0]<<" "<<I[1]<<endl;
      goI(1,(l+r)/2,(l+r+1)/2);
    }
    
  }
  for (i=1; i<(1<<17); i++)
    push(i);
  for ( ; i<n+(1<<17); i++)
    for (j=0; j<26; j++)
      if (A[i][j]==1)
        s[i-(1<<17)]=(char)('a'+j);
  puts(s);
  return 0;
}