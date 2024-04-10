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

const int MAX = 1<<19;

int p[MAX], par[2][MAX];
vector <int> Cv[2][MAX];

int main()
{
  int h;
  scanf("%d", &h);

  REP(i, h+1) scanf("%d", &p[i]);

  par[0][0] = par[1][0] = -1;
  Cv[0][0].push_back(0);
  Cv[1][0].push_back(0);

  int ok = 0;
  int id = 1;

  FOR(i, 1, h+1) {
    if (p[i] > 1 && p[i-1] > 1) {
      ok = 1;

      REP(nov, p[i])
        par[0][id+nov] = Cv[0][i-1][0];

      par[1][id] = Cv[1][i-1][0];
      FOR(nov, 1, p[i])
        par[1][id+nov] = Cv[1][i-1][1];      
    }
    else {
      REP(nov, p[i]) {
        par[0][id+nov] = Cv[0][i-1][0];
        par[1][id+nov] = Cv[1][i-1][0];
      }
    }

    REP(j, p[i]) {
      int tmp = id++;
      Cv[0][i].push_back(tmp);
      Cv[1][i].push_back(tmp);
    }
  }

  if (ok) {
    printf("ambiguous\n");
    REP(j, 2) {
      REP(i, id) printf("%d ", par[j][i] + 1);
      printf("\n");
    }
  }
  else printf("perfect\n");

  return 0;
}