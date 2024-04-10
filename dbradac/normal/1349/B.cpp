#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<17;

int k;
int pref[MAX];
int n;

int main()
{
  int tt;
  scanf("%d", &tt);

  while(tt--) {
    int da = 0, exists = 0;

    scanf("%d%d", &n, &k);
    REP(i, n+3) pref[i] = 0;

    pref[0] = 0;
    int mn = 1e9;

    FOR(i, 1, n+1) {
      int x;
      scanf("%d", &x);
      if (n == 1 && x == k) da = 1;

      pref[i] = pref[i-1] - 1;
      if (x >= k) pref[i] += 2;

      if (i > 1)
        mn = min(mn, pref[i-2]);

      if (mn - pref[i] < 0)
        da = 1;

      if (x == k) exists = 1;
   }

    if (da && exists) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}