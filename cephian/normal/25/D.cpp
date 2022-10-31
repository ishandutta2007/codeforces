#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int n;
bool g[1005][1005];
bool dfs[1005][1005];
bool visit[1005];
vector<vector<int> > components;
vector<pii> closed, built;

void fc(vector<int>& a, int v) {
  visit[v] = 1;
  a.push_back(v);
  for(int u = 1; u <= n; ++u)
    if(g[v][u] && !visit[u]) {
      dfs[v][u] = dfs[u][v] = 1;
      fc(a, u);
    }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      g[i][j] = dfs[i][j] = 0;
  for(int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    g[a][b] = g[b][a] = 1;
  }
  fill(visit, visit+n+1, 0);
  for(int i = 1; i <= n; ++i) {
    if(visit[i]) continue;
    vector<int> v;
    fc(v, i);
    components.push_back(v);
  }
  for(int i = 1; i < components.size(); ++i)
    built.push_back(pii(components[i-1][0], components[i][0]));
  for(int i = 0; i < components.size(); ++i) {
    for(int j = 0; j < components[i].size(); ++j) {
      for(int k = j+1; k < components[i].size(); ++k) {
        int a = components[i][j], b = components[i][k];
        if(!dfs[a][b] && g[a][b])
          closed.push_back(pii(a, b));
      }
    }
  }
  cout << built.size() << endl;;
  for(int i = 0; i < closed.size(); ++i)
    cout << closed[i].first << " " << closed[i].second << " " << built[i].first << " " << built[i].second << "\n";
}