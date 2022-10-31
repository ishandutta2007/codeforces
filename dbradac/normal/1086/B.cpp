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

int deg[MAX];

int main()
{
  int n, s;
  scanf("%d%d", &n, &s);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    deg[a]++; deg[b]++;
  }

  int cnt=0;
  REP(i, n) if (deg[i] == 1) cnt++;

  printf("%.14lf\n", 2.0 * s / cnt);

  return 0;
}