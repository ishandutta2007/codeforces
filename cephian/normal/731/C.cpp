#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
typedef vector<vector<int> > graph;

const int N = 200005;
int n,m,k;
graph G;
int c[N];
int ans = 0;
map<int,int> f;
int visit[N]={0};
int col;

void get_col(int v) {
  visit[v] = 1;
  ++f[c[v]];
  for(int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i];
    if(visit[u] == 1) continue;
    get_col(u);
  }
}

void paint(int v) {
  visit[v] = 2;
  if(c[v] != col) ++ans;
  for(int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i];
    if(visit[u] == 2) continue;
    paint(u);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  G = graph(n,vector<int>());
  for(int i = 0; i < n; ++i)
    cin >> c[i];

  for(int i = 0; i < m; ++i) {
    int u,v;
    cin >> u >> v;
    G[--u].push_back(--v);
    G[v].push_back(u);
  }

  for(int i = 0; i < n; ++i) {
    if(visit[i] == 2) continue;
    f.clear();
    get_col(i);
    int mxcol = -1;
    for(map<int,int>::iterator i = f.begin(); i != f.end(); ++i) {
      if(mxcol == -1 || i->second > f[mxcol])
        mxcol = i->first;
    }
    col = mxcol;
    paint(i);
  }
  cout << ans << "\n";
  return 0;
}