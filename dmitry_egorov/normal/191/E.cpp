#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <ctime>
#include <stack>

#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define pb push_back
#define mp make_pair
#define zero(a) memset (a, 0, sizeof(a))



#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


const int inf = (int)1e9;

long long A[110000], P[18][110000], S[18][110000];
int n;
long long cnt, m;
int B[110000][2];

long long mr (int lv, int id) 
{
  long long ret=0;
  int sl=B[id][0], sr=B[id][1], pl=B[id+1][0], pr=B[id+1][1];
  while (sl<=sr)
  {
    while (S[lv][sl]+P[lv][pl]<m && pl<=pr)
      pl++;
    ret+=pr-pl+1, sl++;
  }
  //cerr<<B[id][0]<<" "<<B[id][1]<<"      "<<B[id+1][0]<<" "<<B[id+1][1]<<"       "<<ret<<endl;
  //cerr<<S[lv][B[id][0]]<<"  "<<P[lv][B[id+1][0]]<<endl;
  return ret;
}

bool can ()
{
  long long ct=cnt;
  int i, lv=0, e, ee;
  for (e=n, i=0; i<n; i++)
    B[i][0]=i, B[i][1]=i, ct-=(long long)(A[i]>=m);
  while (e>1)        
  {
    ee=e, e=0;
//    cerr<<lv<<" !!!!!!!!!!!!!!!!!!! "<<ct<<"    "<<ee<<endl;
    for (i=0; i<ee; i++)
    {
      if (i<ee-1)
        ct-=mr(lv,i), B[e][0]=B[i][0], B[e][1]=B[i+1][1], e++, i++;
      else
        B[e][0]=B[i][0], B[e][1]=B[i][1], e++;
    }
    if (ct<=0)
      return 1;
    lv++;
  }
  return ct<=0;
}

int main (void)
{
  long long l, r;
  int i, j, k;
  #ifdef LOCAL
    freopen (".in", "r", stdin);
    freopen (".out", "w", stdout);
  #endif                              
  scanf("%d%I64d", &n, &cnt);
  for (i=0; i<n; i++)
    scanf("%I64d", &A[i]);
  for (i=0; i<18; i++)
  {
    for (j=0; j<n; j+=(1<<i))
    {
      for (P[i][j]=A[j], k=1; k<(1<<i) && k+j<n; k++)
        P[i][j+k]=P[i][j+k-1]+A[j+k];
      sort(P[i]+j,P[i]+min(n,j+(1<<i)));
    }
    for (j=0; j<n; j+=(1<<i))
    {
      for (S[i][min(n,j+(1<<i)-1)]=A[min(n,j+(1<<i)-1)], k=min(n,j+(1<<i)-1)-1; k>=j; k--)
        S[i][k]=S[i][k+1]+A[k];
      sort(S[i]+j,S[i]+min(n,j+(1<<i)), greater<long long>());
    }
  }
  l=-(long long)1e18, r=(long long)1e18;
  //m=2, printf("%d\n", can());
  while (r-l>1ll)
    m=(l+r)/2, (can())?(l=(l+r)/2):(r=(l+r)/2);
  printf("%I64d\n", l);
  return 0;
}