#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef linux
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

#define sz(x) ((int)(x).size())

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

const int mod = inf+7;

inline void madd (int& a, int b)
{
  a+=b;
  if (a>=mod)
    a-=mod;
}

int mul (int a, int b)
{
  return (a*1ll*b)%mod;
}

pii operator - (const pii& a, const pii& b)
{
  return mp(a.first-b.first,a.second-b.second);
}
                         
ll operator ^ (const pii& a, const pii& b)
{
  return a.first*1ll*b.second-a.second*1ll*b.first;
}

int n;
//bool can[210][210];
int D[210][210];
pii P[410];
ll S[210][210][210];

inline bool check (int a, int b, int c)
{
  //cerr<<a<<" "<<b<<" "<<c<<endl;
  int i;
  ll s=S[a][b][c];
  for (i=0; i<a; i++)
    if (S[a][b][i]+S[b][c][i]+S[c][a][i]==s)
      return 0;
  for (i=a+1; i<b; i++)
    if (S[a][b][i]+S[b][c][i]+S[c][a][i]==s)
      return 0;
  for (i=b+1; i<c; i++)
    if (S[a][b][i]+S[b][c][i]+S[c][a][i]==s)
      return 0;
  for (i=c+1; i<n; i++)
    if (S[a][b][i]+S[b][c][i]+S[c][a][i]==s)
      return 0;
  //cerr<<a<<" "<<b<<" "<<c<<endl;
  return 1;
}

int main()
{
  int i, j, len, k;//l, r;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d", &n);
  for (i=0; i<n; i++)
    scanf("%d%d", &P[i].first, &P[i].second);
  for (i=n-1; i>=0; i--)
    P[i]=P[i]-P[0];
  ll s=0;
  for (i=1; i<n-1; i++)
    s+=(P[i]^P[i+1]);
  if (s<0)
    reverse(P+1,P+n);
  for (i=0; i<n; i++)
    P[i+n]=P[i];
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      for (k=0; k<n; k++)
        S[i][j][k]=abs((P[i]-P[k])^(P[j]-P[k]));
  //TIMESTAMP(cs);
  /*for (i=0; i<n; i++)
    for (j=0; j<n; j++)
      if (i!=j)
      {
        can[i][j]=1;
        pii diff=P[j]-P[i];
        if (i<j)
          l=i+1, r=j;
        else
          l=i+1, r=j+n;
        while (l<r)
        {
          if (((P[l]-P[i])^diff)<=0)
          {
            can[i][j]=0;
            break;
          }
          l++;
        }
        //cerr<<i<<" "<<j<<" "<<can[i][j]<<endl;
      }   */
  for (i=0; i<n-1; i++)
    D[i][i+1]=1;
  for (len=2; len<n; len++)
    for (i=0; i+len<n; i++)
    {
      for (j=i+1; j<i+len; j++)
      {
        if (check(i,j,i+len))
          madd(D[i][i+len],mul(D[i][j],D[j][i+len]));
      }
      //cerr<<len<<" "<<i<<" "<<D[[j]
    }
  printf("%d\n", D[0][n-1]);
  TIMESTAMP(end);
  return 0;
}