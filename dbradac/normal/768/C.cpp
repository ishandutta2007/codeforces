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

const int MAX = 1030;

int p[2][MAX];

int main()
{
  int n, kol, x;

  scanf("%d%d%d", &n, &kol, &x);
  
  REP(i, n) {
    int tmp;
    scanf("%d", &tmp);
    p[0][tmp]++;
  }

  int ind = 0;
  for (; kol--; ind ^= 1) {
    memset(p[1^ind], 0, sizeof p[1^ind]);

    int st = 1;
    REP(i, MAX) {
      int prom = (p[ind][i] + st) / 2;
      p[1^ind][i ^ x] += prom;
      p[1^ind][i] += p[ind][i] - prom;
      st ^= (p[ind][i] & 1);
    }
  }
  
  int mn = MAX, mx = -MAX;
  REP(i, MAX)
    if (p[ind][i]) {
      mn = min(mn, i);
      mx = max(mx, i);
    }

  printf("%d %d\n", mx, mn);

  return 0;
}