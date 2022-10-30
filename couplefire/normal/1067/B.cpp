#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> adj[N];
vector<int> leaves;
int n, k;

int findFar(int src){
  deque<int> d;
  d.push_back(src);
  bool visited[N] = {0};
  int dis[N];
  dis[src] = 0;
  int ma = 0;
  int cor = src;
  while(!d.empty()){
    int t = d.front();
    d.pop_front();
    visited[t] = true;
    if(adj[t].size()==1){
      if(dis[t] > ma){
        ma = dis[t];
        cor = t;
      }
    }
    for(int i = 0; i<adj[t].size(); i++){
      if(!visited[adj[t][i]]){
        d.push_back(adj[t][i]);
        dis[adj[t][i]] = dis[t]+1;
      }
    }
  }
  return cor;
}

void getDis(int src, int (&l)[N]){
  deque<int> d;
  d.push_back(src);
  bool visited[N] = {0};
  int dis[N];
  dis[src] = 0;
  while(!d.empty()){
    int t = d.front();
    d.pop_front();
    visited[t] = true;
    if(dis[t] == k) l[t] = 1;
    for(int i = 0; i<adj[t].size(); i++){
      if(!visited[adj[t][i]]){
        d.push_back(adj[t][i]);
        dis[adj[t][i]] = dis[t]+1;
      }
    }
  }
}

bool isTrue(int src){
  deque<int> d;
  d.push_back(src);
  bool visited[N] = {0};
  int dis[N];
  dis[src] = 0;
  if(adj[src].size() < 3) return false;
  while(!d.empty()){
    int t = d.front();
    d.pop_front();
    visited[t] = true;
    if(t != src && adj[t].size() != 1 && adj[t].size() < 4) return false;
    if(adj[t].size() == 1 && !(dis[t] == k)) return false;
    if(dis[t] == k && !(adj[t].size() == 1)) return false;
    for(int i = 0; i<adj[t].size(); i++){
      if(!visited[adj[t][i]]){
        d.push_back(adj[t][i]);
        dis[adj[t][i]] = dis[t]+1;
      }
    }
  }
  return true;
}

int main() {
  cin >> n >> k;
  for(int i = 0; i<n-1; i++){
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(int i = 0; i<n; i++){
    if(adj[i].size() == 1) leaves.push_back(i);
  }
  if(leaves.size()<3){
    cout << "NO" << endl;
    return 0;
  }
  int f = leaves[0];
  int s = findFar(f);
  int fl[N] = {0};
  int sl[N] = {0};
  getDis(f, fl);
  getDis(s, sl);
  int com = -1;
  for(int i = 0; i<n; i++){
    if(fl[i] == 1 && sl[i] == 1) com = i;
  }
  if(com == -1){
    cout << "NO" << endl;
    return 0;
  }
  if(isTrue(com)) cout << "YES" << endl;
  else cout << "NO" << endl;
}