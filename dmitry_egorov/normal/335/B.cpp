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

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

int D[110][51000], Prev[110][51000];
int S[51000], len, N[51000][26];
char s[51000];
  
int main()
{
  int i, j, it;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  gets(s);
  len=strlen(s); 
  for (i=0; i<len; i++)
    S[i]=(int)(s[i]-'a'), assert(0<=S[i] && S[i]<26);
  for (i=0; i<26; i++)
    N[len-1][i]=len, N[len][i]=len;
  for (i=len-2; i>=0; i--)
    memcpy(N[i],N[i+1],sizeof(N[i])), N[i][S[i+1]]=i+1;  
  for (i=0; i<=len; i++)
    D[1][i]=i;
  for (i=0; i<=len; i++)
    D[2][i]=N[i][S[i]];
  for (it=3; it<=100; it++)
  {
    int b=len;
    D[it][len]=len;
    for (i=len-1; i>=0; i--)
    {
      D[it][i]=N[D[it-2][b]][S[i]], Prev[it][i]=b;
      if (D[it-2][i]<D[it-2][b])
        b=i;
    }
  }
  //for (i=1; i<=7; i++)
  //  for (j=0; j<=len; j++)
  //    cout<<i<<" "<<j<<" "<<D[i][j]<<endl;
  for (i=100; i>0; i--)
    for (j=0; j<len; j++)
      if (D[i][j]<len)
      {
        memset(s,0,sizeof(s));
        //cerr<<i<<"  ???   "<<j<<endl;
        int e=0, k=i;
        while (i>=1)
          s[e++]=(char)(S[j]+'a'), j=Prev[i][j], i-=2;
        while (e<k)
          s[e]=s[k-e-1], e++;
        puts(s);
        return 0;
      }
  assert(0);
  TIMESTAMP(end);
  return 0;
}