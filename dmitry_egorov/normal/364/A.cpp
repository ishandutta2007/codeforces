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

int n, A[4100], S[4100], a;
char str[4100];
ll res;
int Cnt[51123][2];
 
int main()
{
  int i, j, s, inv;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf("%d %s", &a, str);  
  n=strlen(str);
  for (i=0; i<n; i++)
    A[i+1]=(int)(str[i]-'0');
  for (i=0; i<n; i++)
    A[i+1]+=A[i];
  for (i=0; i<n; i++)
    for (j=i; j<n; j++)
    {
      s=A[j+1]-A[i];
     // cerr<<"?? "<<s<<"    "<<i<<" "<<j<<endl;
      if (s==0)
      {
        Cnt[0][0]++;
        continue;
      }
      if (a%s!=0)
        continue;
      inv=0;
      if (s>a/s)
        s=a/s, inv=1;
      Cnt[s][inv]++;
      //cerr<<s<<" "<<inv<<endl;
    }
  if (a==0)
    res=2ll*Cnt[0][0]*1ll*((n*(n+1))/2)-Cnt[0][0]*1ll*Cnt[0][0];
  else
    for (i=0; i<51123; i++)
      if (Cnt[i][0]>0)
      {
       // cerr<<i<<"  "<<Cnt[i][0]<<" "<<Cnt[i][1]<<endl;
        if (i*i==a)
          res+=Cnt[i][0]*1ll*Cnt[i][0];
        else
          res+=2ll*Cnt[i][0]*1ll*Cnt[i][1];
      }
  printf("%I64d\n", res);
  TIMESTAMP(end);
  return 0;
}