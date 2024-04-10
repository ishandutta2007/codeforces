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
#define mod (12345)

using namespace std;

bool operator < (pair <long long, int> i, pair <long long, int> j)
{
  if (i.first!=j.first)
    return i.first<j.first;
  return i.second<j.second;
}

bool A[26][124];
int res;
vector <int> B[26];
int P[26];
map <pair <long long, int>, int > Hash;
int e, Q[26], mm=1, Z[26];
int Conv[123][26];

int solve (long long n, int v)
{
  if (Hash.count(mp(n,v))==0)
  {
    int tmp ,tmp2, i, j;
    Hash[mp(n,v)]=0;
    if (n==1)
    {
      //cerr<<"!!!! "<<v<<endl;
      for (tmp=0, tmp2=0, i=0; i<e; i++)
      {
        if (Conv[v][i]>1)
          return 0;
        if (Conv[v][i]==1 || Q[i]==1)
          tmp++;
        if (Conv[v][i]==1)
          tmp2++;
      }
      //cerr<<tmp<<" "<<tmp2<<endl;
      if (tmp2>1)
        return 0;
      if (tmp==0)
        return 0;
      if (tmp2==1)
      {
        Hash[mp(n,v)]=1;
        return 1;
      }
      Hash[mp(n,v)]=tmp;
      return tmp;
    }
    for (i=0; i<mm; i++)
    {
      //cerr<<i<<endl;
      tmp=0;
      for (j=e-1; j>=0; j--)
      {
        //cerr<<j<<" "<<tmp<<" "<<Q[j]<<endl;
        tmp*=Q[j];
        tmp+=(Conv[v][j]-Conv[i][j]+Q[j])%Q[j];
      }
      //cerr<<tmp<<endl;
      Hash[mp(n,v)]=(Hash[mp(n,v)]+solve(n/2,i)*solve(n-(n/2),tmp))%mod;
    }
  }
  //cerr<<n<<" "<<v<<" "<<Hash[mp(n,v)]<<endl;
  return Hash[mp(n,v)];
}

int main()
{
  int c, tmp, i, j, k;
  long long n;
  bool fl, fl2;
  char tmpc;
  //freopen(".in", "r", stdin);
  //freopen(".out", "w", stdout);
  scanf("%I64d%d", &n, &c);
  if (n==0)
  {
    printf("1\n");
    return 0;
  }
  if (c==0)
  {
    printf("0\n");
    return 0;
  }
  for (i=0; i<c; i++)
  {
    scanf(" %c%d", &tmpc, &tmp);
    A[(int)(tmpc-'A')][tmp]=1;
  }
  for (i=0; i<26; i++)
    for (P[i]=1, j=0; j<124; j++)
      if (A[i][j])
        B[i].pb(j), P[i]*=j;
  for (i=0; i<26; i++)
    if (B[i].size()!=0)
      Q[e]=P[i], mm*=P[i], Z[e]=i, e++;
  for (i=0; i<mm; i++)
  {
    j=i;
    for (k=0; k<e; k++)
      Conv[i][k]=j%Q[k],  j/=Q[k];
  }
  for (i=0; i<mm; i++)
  {
    for (fl=1, j=0; j<e; j++)
    {
      for (fl2=1, k=0; k<(int)B[Z[j]].size(); k++)
        if (Conv[i][j]%B[Z[j]][k]==0)
          fl2=0;
      if (fl2)
        fl=0;
    }
    if (fl)
      res=(res+solve(n,i))%mod;  
  }
  //cerr<<Q[0]<<" "<<Q[1]<<endl;
  //cerr<<mm<<" "<<e<<" "<<Z[0]<<" "<<Z[1]<<endl;
  /*for (i=0; i<mm; i++)
  {
    for (j=0; j<e; j++)
      printf("%d ", Conv[i][j]);
    printf("\n");
  }  */
  printf("%d\n", res);
  return 0;
}