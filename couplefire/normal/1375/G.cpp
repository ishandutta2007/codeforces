#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 7;

int n;
int a[N];
vector <int> gr[N];
int s;

void dfs(int v, int pr = 0, int h = 0) {
  s += h;
  for (int to : gr[v]) {
    if (to == pr) continue;
    dfs(to, v, h ^ 1);
  }
}

main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  dfs(1);
  cout << min(s, n - s) - 1;
}