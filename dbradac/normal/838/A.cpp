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

const int MAX = 5005;

int pref[MAX][MAX];
char s[MAX][MAX];
int brred, brstup;

int suma(int r1, int r2, int s1, int s2) {
  int ret = pref[r2][s2];
  if (r1) ret -= pref[r1-1][s2];
  if (s1) ret -= pref[r2][s1-1];
  if (r1 && s1) ret += pref[r1-1][s1-1];
  return ret;
}

int main()
{
  scanf("%d%d", &brred, &brstup);
  
  REP(i, brred)
    scanf("%s", s[i]);

  REP(i, MAX) {
    int tmp = 0;
    REP(j, MAX) {
      if (i < brred && j < brstup)
	tmp += s[i][j] - '0';
      pref[i][j] = (i ? pref[i-1][j] : 0) + tmp;
    }
  }

  int rje = MAX * MAX;
  FOR(k, 2, max(brred, brstup)+1) {
    int sum = 0;
    for (int i=0; i<brred; i+=k) {
      for (int j=0; j<brstup; j+=k) {
	int tmp = suma(i, i+k-1, j, j+k-1);
	sum += min(tmp, k*k-tmp);
      }
    }

    rje = min(rje, sum);
  }

  printf("%d\n", rje);

  return 0;
}