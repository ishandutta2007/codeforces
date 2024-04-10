#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

typedef pair<int, int> P;
typedef long long ll;

int x, y, n;

int query(vector <int> V) {
  REP(i, (int) V.size())
    if (V[i] >= n)
      V.erase(V.begin() + i--);
  
  if (V.empty()) return 0;
  printf("? %d ", (int) V.size());
  for (auto it : V)
    printf("%d ", it+1);
  printf("\n");
  fflush(stdout);

  int tmp;
  scanf("%d", &tmp);
  if (V.size() % 2)
    tmp ^= x;

  if (!tmp) return 0;
  assert(tmp == (x^y));
  return 1;
}

int rje[2][10];
int isti[10];

int main()
{
  scanf("%d%d%d", &n, &x, &y);

  REP(i, 10) {
    vector <int> V;
    REP(j, 1<<10)
      if (((j>>i) & 1) == 0)
	V.push_back(j);

    int tmp = query(V);
    if (tmp) isti[i] = 0;
    else isti[i] = 1;
  }

  int gdje_raz = -1;
  REP(i, 10)
    if (!isti[i])
      gdje_raz = i;

  assert(gdje_raz != -1);
  rje[0][gdje_raz] = 0;
  rje[1][gdje_raz] = 1;
  
  REP(i, 10) {
    if (isti[i]) {
      vector <int> V;
      REP(j, 1<<10)
	if (((j>>i) & 1) == 0 && ((j>>gdje_raz) & 1) == 0)
	  V.push_back(j);

      int tmp = query(V);
      if (tmp) rje[0][i] = rje[1][i] = 0;
      else rje[0][i] = rje[1][i] = 1;
    }
  }

  REP(i, 10) {
    if (!isti[i] && gdje_raz != i) {
      vector <int> V;
      REP(j, 1<<10)
	if (((j>>gdje_raz) & 1) == 0 && ((j>>i) & 1) == 0)
	  V.push_back(j);

      int tmp = query(V);
      if (tmp) {
	rje[0][i] = 0;
	rje[1][i] = 1;
      }
      else {
	rje[0][i] = 1;
	rje[1][i] = 0;
      }
    }
  }

  int a[2] = {0, 0};
  REP(i, 2)
    REP(j, 10)
    if (rje[i][j])
      a[i] |= 1<<j;

  printf("! %d %d\n", a[0] + 1, a[1] + 1);
  fflush(stdout);

  return 0;
}