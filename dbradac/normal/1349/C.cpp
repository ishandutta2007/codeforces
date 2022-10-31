#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>

#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<
#define X first
#define Y second

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1005;

int when[MAX][MAX];
int poc[MAX][MAX];
int R, S;
int pr[4] = {1, 0, -1, 0}, ps[4] = {0, 1, 0, -1};

bool in(int r, int s) {
  return !(r < 0 || r >= R || s < 0 || s >= S);
}

int main()
{
  int q;
  scanf("%d%d%d", &R, &S, &q);

  REP(i, R) {
    char s[1005];
    scanf(" %s", s);
    REP(j, S) poc[i][j] = s[j] - '0';
  }

  memset(when, -1, sizeof when);

  bool any = false;
  REP(i, R) {
    REP(j, S) {
      REP(k, 4) {
        int nr = i + pr[k], ns = j + ps[k];
        if (!in(nr, ns)) continue;

        if (poc[nr][ns] == poc[i][j]) {
          when[i][j] = 0;
          any = true;
        }
      }
    }
  }

  if (!any) {
    REP(qq, q) {
      int i, j;
      ll it;
      scanf("%d%d%lld", &i, &j, &it); i--; j--;
      printf("%d\n", poc[i][j]);
    }

    return 0;
  }

  queue <P> Q;
  REP(i, R) REP(j, S) if (when[i][j] == 0) Q.push(P(i, j));

  while(!Q.empty()) {
    P tmp = Q.front();
    Q.pop();
    REP(k, 4) {
      int nr = tmp.X + pr[k], ns = tmp.Y + ps[k];
      if (!in(nr, ns)) continue;
      if (when[nr][ns] == -1) {
        when[nr][ns] = when[tmp.X][tmp.Y] + 1;
        Q.push(P(nr, ns));
      }
    }
  }

  REP(i, q) {
    int r, s;
    ll it;
    scanf("%d%d%lld", &r, &s, &it); r--; s--;
    if (it <= when[r][s]) printf("%d\n", poc[r][s]);
    else printf("%lld\n", poc[r][s] ^ ((it - when[r][s]) % 2));
  }

  return 0;
}