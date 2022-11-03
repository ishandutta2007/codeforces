#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<int> g[100005];

int used[100005], ok;

void dfs(int v, int col) {
  if (used[v]) {
    if (used[v] != col) ok = false;
    return;
  }
  used[v] = col;

  for (int x : g[v]) {
    dfs(x, 3 - col);
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b); --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ok = true;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i, 1);

  if (!ok) {
    puts("-1");
    return 0;
  }

  int cnt [5] = {0};
  for (int i = 0; i < n; ++i)
    cnt[used[i]]++;

  printf("%d\n", cnt[1]);
  for (int i = 0; i < n; ++i) {
    if (used[i] == 1) printf("%d ", i + 1);
  }
  printf("\n");

  printf("%d\n", cnt[2]);
  for (int i = 0; i < n; ++i) {
    if (used[i] == 2) printf("%d ", i + 1);
  }
  printf("\n");
  return 0;
}