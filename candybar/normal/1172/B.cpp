#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 200005
#define mod 998244353
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n;
ll f[maxn],fct[maxn];
vector <int> adj[maxn];
void dfs(int u,int fa){
  f[u] = fct[adj[u].size()];
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == fa) continue;
    dfs(v,u);
    f[u] = f[u] * f[v] % mod;
  }
}
int main(){
  n = getint();
  fct[0] = 1;
  for(int i = 1;i <= n;i++){
    fct[i] = fct[i - 1] * i % mod;
  }
  for(int i = 1;i < n;i++){
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ll ans = fct[adj[1].size()] * n % mod;
  for(int i = 0;i < (int)adj[1].size();i++){
    dfs(adj[1][i],1);
    ans = ans * f[adj[1][i]] % mod;
  }
  printf("%I64d\n",ans);
  return 0;
}