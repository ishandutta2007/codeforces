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

const int SZ = 71000/32;
int A[71000];
unsigned int u[SZ], M[35];
            
inline bool get (int x)
{
  //cerr<<v<<" "<<x<<endl;
  return ((u[x>>5]&(1u<<(x&31)))!=0u);
}

bool ug[71000];
vpii V;
int R[71000];
vi RR[71000];
pii O[71000];
int P[71000];

int main()
{
  int n, s, i, j, k;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  for (i=0; i<32; i++)
    for (j=0; j<32-i; j++)
      M[i]|=(1u<<j);

  scanf("%d%d", &n, &s);
  for (i=0; i<n; i++)
    scanf("%d", &O[i].first), O[i].second=i+1;  

  /*n=70000, s=70000;
  for (i=0; i<n; i++)
    O[i].first=1, O[i].second=i+1;*/

  sort(O,O+n);
  if (O[n-1].first>s)
  {
    puts("-1");
    return 0;
  }
  for (i=0; i<n; i++)
    A[i]=O[i].first;
  u[0]=1;
  for (i=0; i<n-1; i++)
  {
    /*u[i+1][j+off]|=((u[i][j]&M[sd])<<sd);
      if (sd)
        u[i+1][j+off+1]|=(u[i][j]&(~M[sd]))>>(32-sd);*/
    int sd=(A[i]&31), off=A[i]>>5;
    for (j=SZ-2-off; j>=0; j--)
    {
      if ((~u[j+off+1])&((u[j]&(~M[sd]))>>(32-sd)))
      {
        for (k=1; k<=sd; k++)
        {

          #ifdef LOCAL 
          assert((((j+off+1)<<5)+(sd-k))-((j<<5)+(32-k))==A[i]);
          #endif

          if ((!get(((j+off+1)<<5)+(sd-k))) && get((j<<5)+(32-k)))
            P[((j+off+1)<<5)+(sd-k)]=i;
        }
        u[j+off+1]|=((u[j]&(~M[sd]))>>(32-sd));
      }
      if ((~u[j+off])&((u[j]&M[sd])<<sd))
      {
        for (k=31-sd; k>=0; k--)
        {

          #ifdef LOCAL 
          assert((((j+off)<<5)+k+sd) - ((j<<5)+k) ==A[i]);
          #endif

          if ((!get(((j+off)<<5)+k+sd)) && get((j<<5)+k))
            P[((j+off)<<5)+k+sd]=i;
        }
        u[j+off]|=((u[j]&M[sd])<<sd);
      }
    }
    //for (j=0; j<80; j++)
    //  printf("%d ", (int)get(j));
    //printf("\n");
  }
  if (!get(s-O[n-1].first)) 
  {
    puts("-1");
    return 0;
  }
  ug[n-1]=1;
  int ss=s-O[n-1].first;
  while (ss>0)
    ug[P[ss]]=1, ss-=A[P[ss]];
  assert(ss==0);
  for (i=0; i<n; i++)
    if (!ug[i])
      V.pb(mp(A[i],i));
  sort(V.begin(),V.end());
  reverse(V.begin(),V.end());
  for (i=0; i<n; i++)
    if (ug[i])
    {
      if ((int)V.size()!=0 && V[0].first<=A[i])
      {
        R[O[i].second]=A[i]-V[0].first, RR[O[i].second].pb(O[V[0].second].second);
        for (j=0; j<(int)V.size(); j++)
        {
          if (j!=(int)V.size()-1)
          {
            R[O[V[j].second].second]=V[j].first-V[j+1].first;
            RR[O[V[j].second].second].pb(O[V[j+1].second].second);
          }
          else
            R[O[V[j].second].second]=V[j].first;
        }
        V.clear(); 
        continue;
      }
      R[O[i].second]=A[i];
    }
  assert((int)V.size()==0);
  for (i=1; i<=n; i++, printf("\n"))
    for (printf("%d %d", R[i], RR[i].size()), j=0; j<(int)RR[i].size(); j++)
      printf(" %d", RR[i][j]);
  TIMESTAMP(end);
 // for(;;);
  return 0;
}