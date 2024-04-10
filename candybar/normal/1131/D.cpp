#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
int par[maxn << 1],n,m,u[maxn * maxn],v[maxn * maxn],E;
void ini(int x){
  for(int i = 1;i <= x;i++){
    par[i] = i;
  }
}
int fin(int x){
  if(par[x] == x) return x;
  return par[x] = fin(par[x]);
}
void uni(int x,int y){
  x = fin(x),y = fin(y);
  if(x == y) return;
  par[x] = y;
}
char s[maxn];
vector <int> adj[maxn << 1];
int deg[maxn << 1],num[maxn << 1];
int main(){
  scanf("%d%d",&n,&m);
  ini(n + m);
  for(int i = 1;i <= n;i++){
    scanf("%s",s + 1);
    for(int j = 1;j <= m;j++){
      if(s[j] == '<'){
        E++;
        u[E] = i, v[E] = n + j;
      }else if(s[j] == '>'){
        E++;
        u[E] = n + j, v[E] = i;
      }else{
        uni(i,n + j);
      }
    }
  }
  for(int i = 1;i <= E;i++){
    u[i] = fin(u[i]), v[i] = fin(v[i]);
    if(u[i] == v[i]){
      puts("No");
      return 0;
    }
    deg[v[i]]++;
    adj[u[i]].push_back(v[i]);
  }
  queue <int> que;
  for(int i = 1;i <= n + m;i++){
    if(deg[i] == 0){
      num[i] = 1;
      que.push(i);
    }
  }
  for(int i = 1;i <= n + m;i++){
    if(que.empty()){
      puts("No");
      return 0;
    }
    int u = que.front(); que.pop();
    for(int i = 0;i < (int)adj[u].size();i++){
      int v = adj[u][i];
      deg[v]--;
      num[v] = max(num[v],num[u] + 1);
      if(deg[v] == 0) que.push(v);
    }
  }
  puts("Yes");
  for(int i = 1;i <= n;i++){
    printf("%d ",num[fin(i)]);
  }
  printf("\n");
  for(int i = n + 1;i <= n + m;i++){
    printf("%d ",num[fin(i)]);
  }
  printf("\n");
  return 0;
}