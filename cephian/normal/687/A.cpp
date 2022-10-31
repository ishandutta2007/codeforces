#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<int> > graph;
typedef pair<int, int> pii;

int col[100005]={0};
graph G;
vector<pii> stack;

void color(int v) {
  if(col[v]) return;
  stack.clear();
  stack.push_back(pii(v,1));
  while(!stack.empty()) {
    pii p = *stack.rbegin();
    stack.pop_back();
    col[p.first] = p.second;
    for(int i = 0; i < G[p.first].size(); ++i)
      if(!col[G[p.first][i]])
        stack.push_back(pii(G[p.first][i], 3-p.second));
  }
}

int main() {
  ios::sync_with_stdio(0);
  int n,m;
  cin >> n >> m;
  G = graph(n,vector<int>());
  while(m--) {
    int u,v;
    cin >> u >> v;
    G[--u].push_back(--v);
    G[v].push_back(u);
  }
  for(int i = 0; i < n; ++i)
    color(i);
  int c1 = 0;
  int c2 = 0;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < G[i].size(); ++j) {
      if(col[G[i][j]] == col[i]) {
        cout << "-1\n";
        return 0;
      }
    }
    if(col[i]==1) ++c1;
    else ++c2;
  }
  cout << c1 << "\n";
  for(int i = 0; i < n; ++i)
    if(col[i]==1) cout << i+1 << " ";
  cout << "\n" << c2 << "\n";
  for(int i = 0; i < n; ++i)
    if(col[i]==2) cout << i+1 << " ";
  cout << "\n";
  return 0;
}