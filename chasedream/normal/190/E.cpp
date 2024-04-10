#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
vector <int> querys;
vector <int> adj[N];
vector <int> ans[N];
int mark[N], n, m, cnt;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    querys.push_back(i);
  }
  while (querys.size()) {
    cnt++;
    vector <int> &res = ans[cnt], tmp;
    res.push_back(querys.back());
    mark[querys.back()] = 1;
    querys.pop_back();

    for (int i = 0; i < res.size(); i++) {
      int u = res[i];
      for (auto v: adj[u]) {
        if (!mark[v]++) tmp.push_back(v);
      }
      for (auto v: querys) {
        if (!mark[v]++) res.push_back(v);
      }
      querys.clear(); querys.swap(tmp);
      for (auto v: querys) mark[v] = 0;
    }
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) {
    printf("%d", ans[i].size());
    for (auto v: ans[i]) printf(" %d", v);
    puts("");
  }
  return 0;
}