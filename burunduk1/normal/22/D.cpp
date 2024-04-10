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

const int maxn = 1010;

struct segment
{
  int L, R;
};

bool operator < ( segment a, segment b )
{
  return a.R < b.R;
}

int n;
segment s[maxn];

int main()
{
  scanf("%d", &n);
  forn(i, n)
  {
    scanf("%d%d", &s[i].L, &s[i].R);
    if (s[i].L > s[i].R)
      swap(s[i].L, s[i].R);
  }
  sort(s, s + n);

  int M = -(int)2e9;
  vi res;
  forn(i, n)
    if (s[i].L > M)
      res.pb(M = s[i].R);

  printf("%d\n", sz(res));
  forn(i, sz(res))
    printf("%d ", res[i]);
  return 0;
}