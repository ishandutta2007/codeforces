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

string s[8]={"vaporeon","jolteon","flareon","espeon","umbreon","leafeon","glaceon","sylveon"};
                         
int main()
{
  int n;
  string str;
  #ifdef LOCAL
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif
  scanf(" %d ", &n);
  cin>>str;
  for (int i=0; i<8; i++)
  {
    if ((int)s[i].length()!=n)
      continue;
    bool fl=1;
    for (int j=0; j<n; j++)
      if (s[i][j]!=str[j] && str[j]!='.')
      {
        fl=0;
        break;
      }
    if (fl)
    {
      cout<<s[i]<<endl;
      return 0;
    }
  }
  assert(0);
  TIMESTAMP(end);
  return 0;
}