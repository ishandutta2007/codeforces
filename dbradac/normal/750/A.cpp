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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

int main()
{
  int n, k, t = 240;
  scanf("%d%d", &n, &k);
  t -= k;

  int r = 0;
  for (int i=1; i<=n; i++) {
    if (t >= 5 * i) {
      r++;
      t -= 5 * i;
    }
  }

  printf("%d\n", r);

  return 0;
}