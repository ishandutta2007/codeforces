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

int n;
int p[MAX];

int main()
{
  int k;
  scanf("%d%d", &n, &k);
  REP(i, n) scanf("%d", &p[i]);

  int ost = p[0] % k;
  int da = 1;
  int mn = p[0];
  ll sum = 0;
  REP(i, n) {
    if (p[i] % k != ost)
      da = 0;
    mn = min(mn, p[i]);
    sum += p[i];
  }

  if (!da) printf("-1\n");
  else
    printf("%lld\n", (sum - (ll) n * mn) / k);  

  return 0;
}