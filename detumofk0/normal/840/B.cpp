#include <bits/stdc++.h>

using namespace std;

const int N = 300030;

int n, m;
int a[N], visited[N];
vector < int > answer;
vector < pair < int, int > > g[N];

void dfs1(int v, int p) {
  visited[v] = 1;
  for(auto e : g[v]) {
    int s = e.first, id = e.second;
    if(visited[s]) continue;
    dfs1(s, v);
    if(a[s] == 1) answer.push_back(id);
    if(a[v] != -1 && a[s] != -1) a[v] ^= a[s];
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  if(fopen("1.inp", "r")) freopen("1.inp", "r", stdin);

  cin >> n >> m;
  for(int i = 1; i <= n; ++i) cin >> a[i];

  for(int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].emplace_back(v, i);
    g[v].emplace_back(u, i);
  }

  if(*min_element(a + 1, a + n + 1) == -1) {
    int root;
    for(int i = 1; i <= n; ++i) if(a[i] == -1) {
      root = i;
    }
    dfs1(root, 0);
  }
  else {
    int check = 0;
    for(int i = 1; i <= n; ++i) check ^= a[i];
    if(check) {
      cout << -1;
      return 0;
    }
    dfs1(1, 0);
  }

  cout << answer.size() << endl;
  for(int x : answer) cout << x << " ";
  cout << endl;

  return 0;
}