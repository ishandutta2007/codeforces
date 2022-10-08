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

int is[maxn * 2];
int pn, p[maxn];

int main()
{
  for (int i = 2; i < maxn; i++)
    if (!is[i])
    {
      p[pn++] = i;
      for (int j = i + i; j < maxn; j += i)
        is[j] = 1;
    }
  forn(i, pn - 1)
    is[p[i] + p[i + 1] + 1] |= 2;
    
  int n, k;
  scanf("%d%d", &n, &k);

  int cnt = 0;
  for (int i = 2; i <= n; i++)
    cnt += (is[i] == 2);
  //printf("cnt = %d\n", cnt);
  puts(cnt >= k ? "YES" : "NO");
  return 0;
}