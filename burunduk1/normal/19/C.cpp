#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = (int)1e5 + 10;
const ll P = (int)1e9 + 7;

int n, L, a[maxn];
map <int, vi> m;
ll hash[maxn], p[maxn];

vector < pair<int,int> > rep;

inline ll Str( int i, int len )
{
  return hash[i + len] - hash[i] * p[len];
}             

inline int Eq( int i, int j )
{
  int len = j - i;
  if (j + len > n)
    return 0;
  return Str(j, len) == Str(i, len);
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &a[i]), m[a[i]].pb(i);

  hash[0] = 1, p[0] = 1;
  forn(i, n)
  {
    hash[i + 1] = hash[i] * P + a[i];
    p[i + 1] = p[i] * P;
  }

  forit(it, m)
  {
    vi &v = it->second;
    forn(i, sz(v))
      forn(j, i)
        if (Eq(v[j], v[i]))
          rep.pb(mp(v[i] - v[j], v[j]));
  }    
  
  sort(all(rep));
  L = 0;
  forn(i, sz(rep))
  {
    int pos = rep[i].second;
    int len = rep[i].first;

    if (pos >= L)
      L = pos + len;
  }

  printf("%d\n", n - L);
  for (int i = L; i < n; i++)
    printf("%d ", a[i]);
  return 0;
}