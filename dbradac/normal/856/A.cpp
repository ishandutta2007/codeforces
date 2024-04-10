#include <bitset>
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

const int MAX = 1<<21, MAXN = 105;

bitset <MAX> nemoze;
int p[MAXN];

int main()
{
  int brt;
  scanf("%d", &brt);

  for (; brt--;) {
    int n;
    printf("YES\n");
    scanf("%d", &n);
    REP(i, n) scanf("%d", &p[i]);

    nemoze.reset();

    int naso = 0;
    FOR(i, 1, MAX) {
      if (naso == n) break;
      assert(i <= 1000000);

      if (!nemoze[i]) {
	naso++;
	printf("%d ", i);
	REP(j, n)
	  REP(k, n)
	  if (p[j] - p[k] + i > 0)
	    nemoze[p[j] - p[k] + i] = 1;
      }
    }
    printf("\n");
  }

  return 0;
}