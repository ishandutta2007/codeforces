#include <bits/stdc++.h>
using namespace std;

vector<long long> *adj;

void bfs(vector<long long> adj[], long long s, long long n);

int main() {
  long long n, m;
  cin >> n >> m;
  adj = new vector<long long>[n];
  pair<long long, long long> mostC(0,0);
  for(long long i = 0; i<m; i++){
    long long a, b;
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
    if(adj[a-1].size() > mostC.first){
      mostC.first = adj[a-1].size();
      mostC.second = a-1;
    }
    if(adj[b-1].size() > mostC.first){
      mostC.first = adj[b-1].size();
      mostC.second = b-1;
    }
  }
  bfs(adj, mostC.second, n);
}

void bfs(vector<long long> adj[], long long s, long long n){
  long long visited[n];
  memset(visited, 0, n*sizeof(long long));
  visited[s] = 1;
  deque<long long> q;
  q.push_back(s);
  while(!q.empty()){
    long long v = q.front();
    q.pop_front();
    visited[v] = 1;
    for(auto i : adj[v]){
      if(visited[i] == 0){
        visited[i] = 1;
        q.push_back(i);
        cout << v+1 << " " << i+1 << endl;
      }
    }
  }
}