#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<vector<int> > graph;

int n, m;
graph G;
graph U;
bool visit[100005]={0};
int scc[100005];
int wcc[100005];

vector<int> order;
void dfs1(int v) {
  if(visit[v]) return;
  visit[v] = 1;
  for(int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i];
    if(!visit[u])
      dfs1(u);
  }
  order.push_back(v);
}

bool cycle[100005]={};

void dfs2(int v, int id) {
  if(scc[v] != -1) return;
  if(v != id) {
    cycle[wcc[v]] = 1;
  }
  scc[v] = id;
  for(int i = 0; i < G[v].size(); ++i) {
    int u = G[v][i];
    if(scc[u] == -1) {
      dfs2(u, id);
    }
  }
}

set<int> wcc_id;

void dfs3(int v, int id) {
  if(wcc[v] != -1) return;
  wcc[v] = id;
  wcc_id.insert(id);
  for(int i = 0; i < U[v].size(); ++i) {
    int u = U[v][i];
    dfs3(u, id);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  G = graph(n, vector<int>());
  U = graph(n, vector<int>());
  for(int i = 0; i < m; ++i) {
    int a,b;
    cin >> a >> b;
    G[--a].push_back(--b);
    U[a].push_back(b);
    U[b].push_back(a);
  }
  fill(wcc, wcc + n, -1);
  order.reserve(n);
  for(int i = 0; i < n; ++i) {
    dfs1(i);
    dfs3(i, i);
  }
  fill(scc, scc+n, -1);
  for(int i = 0; i < n; ++i) {
    dfs2(order[i], order[i]);
  }

  int ans = n - wcc_id.size();
  for(set<int>::iterator i = wcc_id.begin(); i != wcc_id.end(); ++i) {
    if(cycle[*i])
      ++ans;
  }
  cout << ans << "\n";

  return 0;
}