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
typedef vector <pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const double INF = inf;
const double EPS = eps;

vector <pair <pii, pii> > Res;

void add (const vpii& v1, const vpii& v2)
{
 // cerr<<v1.size()<<" "<<v2.size()<<endl;
  int i, j;
  for (i=0; i<(int)v1.size(); i++)
    for (j=0; j<(int)v2.size(); j++)
      Res.pb(mp(v1[i],v2[j]));  
}

inline bool pal (const string& str, int l, int r)
{
  while (l<r)
  {
    if (str[l]!=str[r])
      return 0;
    l++, r--;
  }
  return 1;
}

int Msk[300];
string Str[300];
map <string, int> Mask, RMask;
map <string, vector <pii> > M, RM;

int main(){
  int i, j, cnt, nmask=0, n, x;
  string tmps, s, s2;
  map <string, vpii> :: iterator it, tmpit;
  map <string, int> :: iterator itmsk;
  #ifdef LOCAL
  freopen(TASKNAME"a.in","r",stdin);
  //freopen(TASKNAME"a.out","w",stdout);
  #endif
  char ss[5];
  for (i=0; i<10; i++)
    ss[0]='0'+i, Str[i]=string(ss,ss+1), Msk[i]=(1<<i);// cerr<<Str[i]<<endl;
  for (i=10; i<256; i++)
    Str[i]=Str[i/10]+Str[i%10], Msk[i]=Msk[i/10]|Msk[i%10];
  for (i=0; i<256; i++)
    for (j=0; j<256; j++)
      tmps=Str[i]+Str[j], M[tmps].pb(mp(i,j)), Mask[tmps]=Msk[i]|Msk[j], reverse(tmps.begin(),tmps.end()), RM[tmps].pb(mp(i,j)), RMask[tmps]=Msk[i]|Msk[j];
  for (scanf("%d", &n), i=0; i<n; i++)
    scanf("%d", &x), nmask|=(1<<x);
  for (cnt=0; cnt<2; cnt++, Mask.swap(RMask), M.swap(RM))
  {
  for (itmsk=Mask.begin(), it=M.begin(); it!=M.end(); it++, itmsk++)
  {
    s=it->first;
    if (itmsk->second!=nmask)
      continue;
    
    //cerr<<s<<" "<<itmsk->second<<"     "<<nmask<<endl;
    for (i=2; i+cnt<=(int)s.length(); i++)
    {
      s2=s.substr(0,i);
     // cerr<<"??? "<<s2<<endl;
      if (pal(s,i,s.length()-1))
      {
       // cerr<<"TTTT"<<endl;
        tmpit=RM.find(s2);
        if (tmpit!=RM.end())
           (cnt)?(add(tmpit->second,it->second)):(add(it->second,tmpit->second));
      }
    }
  }
  }
  printf("%d\n", (int)Res.size());
  for (i=0; i<(int)Res.size(); i++)
    printf("%d.%d.%d.%d\n", Res[i].first.first, Res[i].first.second, Res[i].second.first, Res[i].second.second);
  TIMESTAMP(end);
  return 0;
}