#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <ctime>
#include <queue>
#include <cmath>
#include <set>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<19;

void no() {
  printf("No\n");
  exit(0);
}

int p[2][MAX];
vector <int> A[2];

int main()  
{
  int n;
  scanf("%d", &n);

  REP(i, 2) {
    REP(j, n) {
      scanf("%d", &p[i][j]);
      if (j) A[i].push_back(p[i][j] - p[i][j-1]);
    }
    sort(A[i].begin(), A[i].end());
  }

  if (p[0][0] != p[1][0] || p[0][n-1] != p[1][n-1] || A[0] != A[1])
    no();
  printf("Yes\n");

  return 0;
}