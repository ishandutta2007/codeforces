#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[LEN + 5];
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[15];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(ll x,char suf){
  if(!x) bufo.put('0');
  else{
    if(x < 0) bufo.put('-'), x = -x;
    int k = 0; char s[25];
    while(x){
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for(;k;k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define maxn 100005
const ll infll = 0x3f3f3f3f3f3f3f3fll;
int n,c[3][maxn],a[maxn],res[maxn],d[maxn];
ll ans = infll;
vector <int> adj[maxn];
void dfs(int u,int f,int col,ll cur){
  a[u] = col;
  if(adj[u].size() == 1 && f){
    if(cur + c[col][u] < ans){
      ans = cur + c[col][u];
      memcpy(res,a,sizeof(a));
    }
  }
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == f) continue;
    for(int j = 0;j <= 2;j++){
      if(j != a[u] && j != a[f]) dfs(v,u,j,cur + c[col][u]);
    }
  }
}
int main(){
  n = getint();
  for(int i = 0;i < 3;i++){
    for(int j = 1;j <= n;j++){
      c[i][j] = getint();
    }
  }
  for(int i = 1;i < n;i++){
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
    d[u]++, d[v]++;
  }
  for(int i = 1;i <= n;i++){
    if(d[i] > 2){
      puts("-1");
      return 0;
    }
  }
  for(int i = 1;i <= n;i++){
    if(d[i] == 1){
      a[0] = -1;
      dfs(i,0,0,0); dfs(i,0,1,0); dfs(i,0,2,0);
      printf("%lld\n",ans);
      for(int i = 1;i <= n;i++) printf("%d%c",res[i] + 1,i == n ? '\n' : ' ');
      return 0;
    }
  }
  return 0;
}