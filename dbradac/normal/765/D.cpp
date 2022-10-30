#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cassert>

using namespace std;

#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 1<<20;

int bio[MAX];
int f[MAX], g[MAX], h[MAX];
int invh[MAX];
int n, m;
int ind[MAX];

int check()
{
  REP(i, n) if (g[i] < 0 || g[i] >= m) return 0;
  REP(i, n) if (h[i] < 0 || h[i] >= n) return 0;
  REP(i, m) if (g[h[i]] != i) return 0;
  REP(i, n) if (h[g[i]] != f[i]) return 0;
  return 1;
}

int main()
{
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &f[i]); f[i]--;
    if (!bio[f[i]]) {
      bio[f[i]] = 1;
      m++;
    }
  }

  int vr=0;
  REP(i, n) if (f[i] == i) ind[vr++] = i;

  memset(invh, -1, sizeof invh);
  REP(i, m) {
    h[i] = f[ind[i]];
    invh[h[i]] = i;
  }

  REP(i, n)
    g[i] = invh[f[i]];

  if (check()) {
    printf("%d\n", m);
    REP(i, n) printf("%d ", g[i] + 1);
    printf("\n");
    REP(i, m) printf("%d ", h[i] + 1);
    printf("\n");
  }
  else
    printf("-1\n");

  return 0;
}