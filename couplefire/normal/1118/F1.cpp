#include <bits/stdc++.h>
using namespace std;

vector<int> adj[3*100000+1];
int col[3*100000+1] = {0};
int num1[3*100000+1] = {0};
int num2[3*100000+1] = {0};
int t1 = 0, t2 = 0;
int t = 0;

void dfs(int v, int p){
  if(col[v] == 1) num1[v]++;
  if(col[v] == 2) num2[v]++;
  for(int i = 0; i<adj[v].size(); i++){
    if(adj[v][i] == p) continue;
    dfs(adj[v][i], v);
    num1[v] += num1[adj[v][i]];
    num2[v] += num2[adj[v][i]];
  }
  if(p != -1 && num1[v] == t1 && num2[v] == 0) t++;
  else if(p != -1 && num2[v] == t2 && num1[v] == 0) t++;
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; i++){
    int a;
    scanf("%d", &a);
    col[i] = a;
    if(a == 1) ++t1;
    if(a == 2) ++t2;
  }
  for(int i = 0; i<n-1; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    --a; --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(0, -1);
  cout << t << endl;
}