#include <bits/stdc++.h>
using namespace std;
bool work = true;
int ind = -1;
vector<bool> visiteda(100001, false);
vector<bool> visitedb(100001, false);
vector<int> color(100001, 0);

void dfsa(int v, vector<int> adj[]){
  if(visiteda[v] || ind != -1) return;
  visiteda[v] = true;
  for(int i = 0; i<adj[v].size(); i++){
    if(color[adj[v][i]] != color[v]){
      bool b = true;
      for(int k = 0; k<adj[v].size(); k++){
        if(adj[v][k] == adj[v][i]) continue;
        if(color[adj[v][k]] != color[v]){
          b = false;
          ind = v;
          break;
        }
      }
      if(b) ind = adj[v][i];
    }
    dfsa(adj[v][i], adj);
  }
}

void dfs(int v, vector<int> adj[]){
  if(visitedb[v] || !work) return;
  visitedb[v] = true;
  if(v == ind){
    for(int i = 0; i<adj[v].size(); i++){
      dfs(adj[v][i], adj);
    }
  }
  else{
    for(int i = 0; i<adj[v].size(); i++){
      if(visitedb[adj[v][i]] == false){
        if(color[adj[v][i]] != color[v]) work = false;
        dfs(adj[v][i], adj);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> adj[n];
  for(int i = 0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 0; i<n; i++){
    int c;
    cin >> c;
    color[i] = c;
  }
  dfsa(0, adj);
  if(ind == -1){
    cout << "YES" << endl;
    cout << "1" << endl;
    return 0;
  }
  dfs(ind, adj);
  if(work){
    cout << "YES" << endl;
    cout << ind+1 << endl;
  }
  else cout << "NO" << endl;
}