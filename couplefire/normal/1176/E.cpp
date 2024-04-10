#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int n){
  vector<int> odd, even;
  vector<int> dis(n, 0);
  deque<int> d;
  d.push_back(0);
  vector<bool> visited(n, false);
  visited[0] = true;
  even.push_back(0);
  while(!d.empty()){
    int v = d.front();
    d.pop_front();
    for(int i = 0; i<adj[v].size(); i++){
      if(visited[adj[v][i]]) continue;
      visited[adj[v][i]] = true;
      dis[adj[v][i]] = dis[v]+1;
      if(dis[adj[v][i]] % 2 == 1) odd.push_back(adj[v][i]);
      else even.push_back(adj[v][i]);
      d.push_back(adj[v][i]);
    }
  }
  if(odd.size() < even.size()) swap(odd, even);
  cout << even.size() << endl;
  for(auto i : even) cout << i+1 << " ";
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  for(int j = 0; j<t; j++){
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for(int i = 0; i<m; i++){
      int a, b;
      cin >> a >> b;
      --a; --b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    bfs(adj, n);
  }
}