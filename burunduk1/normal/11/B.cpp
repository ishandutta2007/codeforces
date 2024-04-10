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

int main()
{
  int x;
  while (scanf("%d", &x) == 1)
  {
    int sum = 0, cnt = 0;
    x = abs(x);
    while (sum < x)
      sum += ++cnt;
    while ((sum - x) % 2 != 0)
      sum += ++cnt;
    printf("%d\n", cnt);
//    printf("%d : %d\n", x, cnt);
  }
  return 0;
}