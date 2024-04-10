#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


vector<vector<int> > G;
int most[100005];
bool cat[100005];

int n, m;

void fillamt(int from, int v, int con, int mo) {
  if(cat[v]) ++con;
  else con = 0;
  most[v] = max(con, mo);
  for(int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i];
    if(u == from) continue;
    fillamt(v, u, con, most[v]);
  }
}

int main() {
  //freopen("1.in", "r", stdin);
  cin >> n >> m;
  for(int i = 0; i < n; ++i)
    cin >> cat[i];
  G = vector<vector<int> >(n, vector<int>());
  for(int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    G[--a].push_back(--b);
    G[b].push_back(a);
  }
  fillamt(-1, 0, 0, 0);
  int res = 0;
  for(int i = 1; i < n; ++i) {
    if(G[i].size() == 1 && most[i] <= m)
      ++res;
  }

  cout << res << "\n";
}