#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

ll p[MAX];
ll pref[MAX];
int n;

int main()
{
  scanf("%d", &n);
  FOR(i, 1, n+1) scanf("%lld", &p[i]);

  FOR(i, 1, n) pref[i] = pref[i-1] + abs(p[i] - p[i+1]) * (i % 2 ? 1 : -1);
  pref[n] = pref[n-1];
  
  ll mx = -1e18, mn = 1e18;
  ll rje = 0;
  
  for (int i=n; i>=1; i--) {
    mx = max(mx, pref[i]);
    mn = min(mn, pref[i]);
    if (i % 2) rje = max(rje, mx - pref[i-1]);
    else rje = max(rje, -(mn - pref[i-1]));
  }
  
  printf("%lld\n", rje);

  return 0;
}