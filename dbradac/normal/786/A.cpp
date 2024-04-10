#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define TRACE(x) cerr << #x << " = " << x << endl
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)
#define X first
#define Y second

const int MAX = 7005;

int n;
int go(int a, int b)
{
  a += b;
  if (a >= n) a -= n;
  return a;
}

int wn[2][MAX], ls[2][MAX];
int deg[2][MAX];
int bio[2][MAX];
vector <int> V[2];

int main()
{
  scanf("%d", &n);

  REP(i, 2) {
    int k;
    scanf("%d", &k);
    REP(j, k) {
      int x;
      scanf("%d", &x);
      V[i].push_back(x);
    }

    REP(j, n) deg[i][j] = k;
  }

  ls[0][0] = ls[1][0] = 1;
  queue <P> Q;
  Q.push({0, 0});
  Q.push({1, 0});

  for (; !Q.empty(); ) {
    P tmp = Q.front(); Q.pop();
    if (bio[tmp.X][tmp.Y]++) continue;

    if (wn[tmp.X][tmp.Y]) {
      for (auto it : V[1^tmp.X]) {
	int odakle = (tmp.Y - it); if (odakle < 0) odakle += n;
	deg[1^tmp.X][odakle]--;
	if (!deg[1^tmp.X][odakle] && !wn[1^tmp.X][odakle]) {
	  ls[1^tmp.X][odakle] = 1;
	  Q.push(P(1^tmp.X, odakle));
	}
      }
    }
    else {
      for (auto it : V[1^tmp.X]) {
	int odakle = (tmp.Y - it); if (odakle < 0) odakle += n;
	if (!wn[1^tmp.X][odakle]) {
	  wn[1^tmp.X][odakle] = 1;
	  Q.push(P(1^tmp.X, odakle));
	}
      }
    }
  }

  REP(i, 2) {
    FOR(j, 1, n) {
      if (wn[i][j]) printf("Win ");
      else if (ls[i][j]) printf("Lose ");
      else printf("Loop ");
    }
    printf("\n");
  }

  return 0;
}