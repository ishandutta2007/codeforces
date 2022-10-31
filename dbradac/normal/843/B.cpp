#include <ctime>
#include <unistd.h>
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

ll rnd() {
  return ((ll) rand() << 15) | rand();
}

void ans(int rje) {
  printf("! %d\n", rje);
  fflush(stdout);
  exit(0);
}

int x;
int prije=-123, pozprije;
int bst=-123, pozbst;

P query(int pos) {
  printf("? %d\n", pos);
  fflush(stdout);
  int a, b;
  scanf("%d%d", &a, &b);
  if (a <= x && (prije == -123 || a > prije)) {
    prije = a;
    pozprije = pos;
  }

  if (a >= x && (bst == -123 || a < bst)) {
    bst = a;
    pozbst = pos;
  }

  return P(a, b);
}

int main()
{
  int n, start;
  scanf("%d%d%d", &n, &start, &x);
  P kek = query(start);

  srand(time(0) * getpid());

  if (kek.X <= x) assert(prije != -123);
  if (kek.X >= x) assert(bst != -123);

  REP(i, 1000)
    query((int) (rnd() % n + 1));
  
  int tmp = pozprije;
  REP(i, 990) {
    if (tmp < 1 || tmp > n) break;
    P t = query(tmp);
    tmp = t.Y;
  }

  ans((bst == -123) ? -1 : bst);

  return 0;
}