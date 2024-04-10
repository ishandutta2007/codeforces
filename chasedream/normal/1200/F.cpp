#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define ll long long
const int N = 2520;

queue <pii> q;
int f[N][N], in[N][N];
bool vis[N][N], vis2[N][N], v[N];
int e[N], go[N][13];
int k[N];
int n, big;

inline int add(int x, int y) {
  x += y;
  if(x >= N) x -= N;
  return x;
}
 
void topo() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N; j++) {
      if (!in[i][j])
        q.push(make_pair(i, j));
    }
  }
  
  while (!q.empty()) {
    pii u = q.front(); q.pop();
    int uf = u.first, us = u.second;
    int t = (us + k[uf]) % N, v = go[uf][t % e[uf] + 1];
    if (--in[v][t] == 0) {
      q.push(make_pair(v, t));
    }
  }
}

void dfs1(int i, int j) {
    vis[i][j] = 1; if(!v[i]) { v[i] = 1; ++big; }
    int t = add(j, k[i]), v = go[i][t % e[i] + 1];
    if(!vis[v][t]) dfs1(v, t);
}
 
void dfs2(int i, int j) {
    vis2[i][j] = 1; f[i][j] = big; v[i] = 0;
    int t = add(j, k[i]), v = go[i][t % e[i] + 1];
    if(!vis2[v][t]) dfs2(v, t);
}
 
void dfs3(int i, int j) {
    if(vis[i][j]) { return; } vis[i][j] = 1;
    int t = add(j, k[i]), v = go[i][t % e[i] + 1];
    dfs3(v, t); f[i][j] = f[v][t];
}

int main() { 
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k[i]);
    k[i] = (k[i] % N + N) % N;
  }	
  for (int i = 1; i <= n; i++) {
    scanf("%d", &e[i]);
    for (int j = 1; j <= e[i]; j++)
      scanf("%d", &go[i][j]);
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N; j++) {
      int t = (j + k[i]) % N, v = go[i][t % e[i] + 1];
      in[v][t]++;
    }
  }
  
  topo();
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N; j++) {
      if (!vis[i][j] && in[i][j]) {
        big = 0; dfs1(i, j); dfs2(i, j);
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < N; j++) {
      if (!vis[i][j]) dfs3(i, j);
    }
  }
  
  int m;
  scanf("%d", &m);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    y = (y % N + N) % N;
    printf("%d\n", f[x][y]);
  }
  return 0;
  
}