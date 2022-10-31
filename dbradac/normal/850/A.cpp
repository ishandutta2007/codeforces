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

const int MAX = 1005;

int p[MAX][5];

inline int check(int a, int b, int c) {
  int sum=0;
  REP(i, 5)
    sum += (p[a][i] - p[b][i]) * (p[a][i] - p[c][i]);

  return sum > 0;
}

int main()
{
  int n;
  scanf("%d", &n);
  REP(i, n) REP(j, 5) scanf("%d", &p[i][j]);

  vector <int> T;
  int per[n];
  REP(i, n) per[i] = i;

  random_shuffle(per, per + n);

  REP(i, n) {
    int da=0;
    REP(j, n) {
      FOR(k, j+1, n) {
	if (j != i && k != i && check(per[i], per[j], per[k])) {
	  da = 1;
	  break;
	}
      }
      if (da) break;
    }
    if (!da) T.push_back(per[i]);
  }

  sort(T.begin(), T.end());
  printf("%d\n", (int) T.size());
  for (auto it : T)
    printf("%d ", it+1);
  printf("\n");

  return 0;
}