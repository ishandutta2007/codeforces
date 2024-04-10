#include <bits/stdc++.h>
using namespace std;
#define N 100001

int n;
vector<int> adj[N];
double ans[N];
double siz[N] = {0};

void finds(int v, int p){
  for(int i = 0; i<adj[v].size(); i++){
    if(adj[v][i] == p) continue;
    finds(adj[v][i], v);
    siz[v] += siz[adj[v][i]];
  }
  siz[v]++;
}

void dfs(int v, int prev){
  int temp = adj[v].size();
  if(prev == -1) ans[v] = 1;
  for(double i = 0; i<temp; i+=1){
    if(adj[v][i] == prev) continue;
    ans[adj[v][i]] += ans[v] + 1+(siz[v]-siz[adj[v][i]]-1)/2;
    dfs(adj[v][i], v);
  }
}

int main() {
  cin >> n;
  for(int i = 1; i<n; i++){
    int a;
    scanf("%d", &a);
    --a;
    adj[a].push_back(i);
    adj[i].push_back(a);
  }
  finds(0, -1);
  dfs(0, -1);
  for(int i = 0; i<n; i++){
    printf("%lf ", ans[i]);
  }
  cout << endl;
}