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

#define V(i) ((i) + ((i) >= (v)) + 1)

int main()
{
  int n, m, v;
  scanf("%d%d%d", &n, &m, &v), v--;

  int n1 = n - 1;
  #define E(n) ((n) * ((n) - 1)) / 2
  if (m < n - 1 || m > E(n1) + 1)
  {
    puts("-1");
    return 0;
  }

  n1--;
  m -= n - 1;
  forn(i, n1)
    forn(j, i)
      if (m-- > 0)
        printf("%d %d\n", V(i), V(j));
      else
        i = j = n1;
  forn(i, n) 
    if (i != v)
      printf("%d %d\n", i + 1, v + 1);
  return 0;
}