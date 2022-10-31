#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<18;

char a[MAX], b[MAX];
int br[2][2];

int main()
{
  int n;
  scanf("%d", &n);
  scanf(" %s %s", a, b);

  REP(i, n) {
    br[a[i]-'0'][b[i]-'0']++;
  }

  ll sol = 0;

  REP(a1, 2) {
    REP(b1, 2) {
      int tmp = br[a1][b1]--;
      FOR(a2, a1, 2) {
        REP(b2, 2) {
          if (((a1|b1) != (a2|b1)) || ((a2|b2) != (a1|b2)))
            sol += (ll) tmp * br[a2][b2];
        }
      }

      br[a1][b1]++;
    }
  }

  printf("%lld\n", sol);

  return 0;
}