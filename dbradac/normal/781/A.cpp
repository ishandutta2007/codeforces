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

vector <int> V[MAX];
int rje[MAX];
int ima[MAX];

void dfs(int node, int par)
{
  if (par == -1) rje[node] = 0;
  else
    ima[rje[par]] = 1;
    
  ima[rje[node]] = 1;

  int ind = 0;
  for (auto it : V[node]) {
    if (it == par) continue;
    for (; ima[ind]; ind++);
    rje[it] = ind++;
  }

  ima[rje[node]] = 0;
  if (par != -1) ima[rje[par]] = 0;

  for (auto it : V[node])
    if (it != par)
      dfs(it, node);
}

int main()
{
  int n;
  scanf("%d", &n);

  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  int d = 1;
  REP(i, n)
    d = max(d, (int) V[i].size() + 1);

  printf("%d\n", d);

  dfs(0, -1);
  REP(i, n)
    printf("%d ", rje[i] + 1);
  printf("\n");

  return 0;
}