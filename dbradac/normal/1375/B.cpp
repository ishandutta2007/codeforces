#include <cstdio>
#include <cassert>
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

int main()
{
  int t;
  scanf("%d", &t);
  while(t--) {
    int nr, ns;
    scanf("%d%d", &nr, &ns);
    int ok = 1;

    REP(i, nr) {
      REP(j, ns) {
        int x;
        scanf("%d", &x);
        int neigh = 4;
        if (!i || i == nr-1) neigh--;
        if (!j || j == ns-1) neigh--;
        if (x > neigh) ok = 0;
      }
    }

    if (!ok) printf("NO\n");
    else {
      printf("YES\n");
      REP(i, nr) {
        REP(j, ns) {
          int neigh = 4;
          if (!i || i == nr-1) neigh--;
          if (!j || j == ns-1) neigh--;
          printf("%d ", neigh);
        }
        printf("\n");
      }
    }
  }

  return 0;
}