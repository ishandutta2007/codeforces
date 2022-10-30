#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1001];
vector<bool> visited(1001, false);
vector<int> dists(1001, INT_MAX);
vector<int> distd(1001, INT_MAX);
bool mat[1001][1001] = {};

void bfs(int v, vector<int> &arr){
  visited[v] = true;
  deque<int> d;
  d.push_back(v);
  arr[v] = 0;
  while(!d.empty()){
    int f = d.front();
    d.pop_front();
    for(int i = 0; i<adj[f].size(); i++){
      if(!visited[adj[f][i]]){
        visited[adj[f][i]] = true;
        d.push_back(adj[f][i]);
        arr[adj[f][i]] = arr[f]+1;
      }
    }
  }
}

int main() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  --s;
  --t;
  for(int i = 0; i<m; i++){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
    mat[a][b] = true;
    mat[b][a] = true;
  }
  bfs(s, dists);
  fill(visited.begin(), visited.end(), false);
  bfs(t, distd);
  int re = 0;
  for(int i = 0; i<n; i++){
    for(int k = i+1; k<n; k++){
      if(mat[i][k] == true) continue;
      if(dists[i]+distd[k]+1 >= dists[t] && dists[k]+distd[i]+1 >= dists[t]) re++;
    }
  }
  cout << re << endl;
}