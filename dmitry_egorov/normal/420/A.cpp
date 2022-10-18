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

bool G[30][30];

void add (char a, char b)
{
  G[a-'A'][b-'A']=1;
  G[b-'A'][a-'A']=1;
}
       
char s[123123];

int main()
{
  int i, len;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  add('A','A');
  add('H','H');
  add('I','I');
  add('M','M');
  add('O','O');
  add('T','T');
  add('U','U');
  add('V','V');
  add('W','W');
  add('X','X');
  add('Y','Y');

  gets(s);
  len=strlen(s);
  for (i=0; i<len; i++)
    if (!G[s[i]-'A'][s[len-i-1]-'A'])
    {
      puts("NO");
      return 0;
    }
  puts("YES");
  TIMESTAMP(end);
  return 0;
}