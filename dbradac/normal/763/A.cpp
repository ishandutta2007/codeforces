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

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 1<<17;

int imacol[MAX];
int col[MAX];
int ok[MAX], sub[MAX];
vector <int> V[MAX];
int n;

int dfs_poc(int x, int pr)
{
  imacol[col[x]]++;
  sub[x] = 1;
  ok[x] = 1;

  for (auto it : V[x]) {
    if (it == pr) continue;
    sub[x] += dfs_poc(it, x);
    if (!(ok[it] && col[it] == col[x]))
      ok[x] = 0;
  }

  return sub[x];
}

void dfs(int x, int pr)
{
  int da = 1;
  for (auto it : V[x]) {
    if (it == pr) continue;
    if (!ok[it]) da = 0;
    imacol[col[it]] -= sub[it];
  }
  imacol[col[x]]--;

  if (da && (!x || imacol[col[pr]] == n - sub[x])) {
    printf("YES\n%d\n", x+1);
    exit(0);
  }

  imacol[col[x]]++;
  for (auto it : V[x]) {
    if (it == pr) continue;
    imacol[col[it]] += sub[it];
  }

  for (auto it : V[x]) {
    if (it == pr) continue;
    dfs(it, x);
  }
}

int main()
{
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b;
    scanf("%d%d", &a, &b); a--; b--;
    V[a].push_back(b);
    V[b].push_back(a);
  }

  REP(i, n) scanf("%d", &col[i]);
  dfs_poc(0, -1);
  dfs(0, -1);

  printf("NO\n");

  return 0;
}