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

int n, next[maxn];
int k = 300;
int go[maxn], jump[maxn];

int L, R;

void GetSeg( int i )
{
  L = (i / k) * k;
  R = min(n, L + k);
}

int main()
{
  int m, a, b, type, x;
  scanf("%d%d", &n, &m);
  forn(i, n)
  {
    scanf("%d", &a);
    next[i] = min(n, i + a);
  }
 
  for (int i = 0; i < n; i += k)
  {
    GetSeg(i);
    for (int i = R - 1; i >= L; i--)
      if ((x = next[i]) >= R)
        go[i] = x, jump[i] = 1;
      else
        go[i] = go[x], jump[i] = jump[x] + 1;
  }

  while (m--)
  {
    scanf("%d", &type);
    if (type == 0)
    {
      scanf("%d%d", &a, &b), a--;
      next[a] = min(n, a + b);
      GetSeg(a);

      for (int i = R - 1; i >= L; i--)
        if ((x = next[i]) >= R)
          go[i] = x, jump[i] = 1;
        else
          go[i] = go[x], jump[i] = jump[x] + 1;
    }
    else
    {
      int cnt = 0;
      scanf("%d", &a), a--;

      while (go[a] < n)
        cnt += jump[a], a = go[a];
      while (next[a] < n)
        a = next[a], cnt++;
      printf("%d %d\n", a + 1, cnt + 1);
    }
  }
  return 0;
}