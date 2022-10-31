#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=a; i<b; i++)

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

int p[MAX][2];

int main()
{
  int n;
  int sum[2] = {0, 0};

  scanf("%d", &n);

  REP(i, n)
    REP(j, 2) {
      scanf("%d", &p[i][j]);
      sum[j] += p[i][j];
    }

  int rje = abs(sum[0] - sum[1]);
  int ind = 0;

  REP(i, n) {
    REP(j, 2)
      sum[j] += p[i][j^1] - p[i][j];

    if (abs(sum[0] - sum[1]) > rje) {
      rje = abs(sum[0] - sum[1]);
      ind = i + 1;
    }

    REP(j, 2)
      sum[j] += p[i][j] - p[i][j^1];
  }

  printf("%d\n", ind);

  return 0;
}