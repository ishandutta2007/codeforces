#include <cstdio>
#include <cassert>
#include <numeric>
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

const int MAX = 1<<18;
const int ITER = 60;

vector <int> V[MAX];
int good[MAX];
int n, m;

int col[MAX];
bool dfs(int node) {
  col[node] = 1;

  for (auto it : V[node]) {
    if (col[it] == 0) {
      if (!dfs(it)) return false;
    }
    else if (col[it] == 2) return false;
  }
  col[node] = 2;

  return true;
}

bool check(int root) {

  REP(i, n) col[i] = 0;
  if (!dfs(root)) return false;
  REP(i, n) if (!col[i]) return false;
  return true;
}

P links[MAX]; //two top(smallest depth)
int dub[MAX];

void dfs_calc(int node) {
  col[node] = 1;

  for (auto it : V[node]) {
    if (col[it] == 0) {
      dub[it] = dub[node] + 1;
      dfs_calc(it);
      vector <int> T = vector<int> {links[node].X, links[node].Y, links[it].X, links[it].Y};
      sort(T.begin(), T.end(), [] (int a, int b) { if (a == MAX || b == MAX) return a < b; return dub[a] < dub[b]; });
      if (T[0] < n && dub[T[0]] < dub[node]) links[node].X = T[0];
      if (T[1] < n && dub[T[1]] < dub[node]) links[node].Y = T[1];
    }
    else {
      assert(col[it] == 1);
      vector <int> T = vector<int> {links[node].X, links[node].Y, it};
      sort(T.begin(), T.end(), [] (int a, int b) { if (a == MAX || b == MAX) return a < b; return dub[a] < dub[b]; });
      if (T[0] < n && dub[T[0]] < dub[node]) links[node].X = T[0];
      if (T[1] < n && dub[T[1]] < dub[node]) links[node].Y = T[1];
    }
  }

  col[node] = 2;
} 

int per[MAX];
void calc(int root) {

  REP(i, n) {
    col[i] = 0;
    links[i] = P(MAX, MAX);
  }
  dub[root] = 0;
  dfs_calc(root);

  REP(i, n) per[i] = i;
  good[root] = 1;
  sort(per, per+n, [] (int a, int b) { return dub[a] < dub[b]; });

  FOR(iii, 1, n) {
    int i = per[iii];
    if (links[i].Y == MAX && links[i].X < n && good[links[i].X])
      good[i] = 1;
  }

  good[root] = 1;
}

int main()
{
  srand(1341);

  int tt;
  scanf("%d", &tt);

  while(tt--) {
    scanf("%d%d", &n, &m);
    REP(i, m) {
      int a, b;
      scanf("%d%d", &a, &b); a--; b--;
      V[a].push_back(b);
    }
    
    if (m < n-1) {
      REP(i, n) V[i].clear();
      printf("-1\n");
      continue;
    }

    int yes = 0;
    REP(i, n) good[i] = 0;
    REP(i, ITER) {
      int root = (int) (((((ll) rand())<<15) + rand()) % n);
      if (check(root)) {
        calc(root);
        if (accumulate(good, good+n, 0) * 5 < n) printf("-1");
        else REP(j, n) if (good[j]) printf("%d ", j+1);

        printf("\n");
        yes = 1;
        break;
      }
    }

    REP(i, n) V[i].clear();
    if (!yes) printf("-1\n");
  }

  return 0;
}