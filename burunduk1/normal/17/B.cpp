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

int n, m, q[maxn];
vector <int> c[maxn], w[maxn];

int main()
{
  int n;
  scanf("%d", &n);
  forn(i, n)
    scanf("%d", &q[i]);
  scanf("%d", &m);
  while (m--)
  {
    int a, b, x;
    scanf("%d%d%d", &a, &b, &x);
    a--, b--;
    c[b].pb(a);
    w[b].pb(x);
  }

  ll sum = 0, cnt = 0;
  forn(i, n)
    if (sz(c[i]))
    {
      int mi = w[i][0];
      forn(j, sz(w[i]))
        mi = min(mi, w[i][j]);
      sum += mi;
    }
    else
      cnt++;
  cout << (cnt > 1 ? -1 : sum) << endl;
  return 0;
}