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
#define maxn 3005
#define mp make_pair
typedef pair<int,int> P;
int n,par[12][maxn],siz[maxn],dep[maxn],dis[maxn][maxn];
vector <int> adj[maxn];
void dfs(int u,int f){
  dep[u] = dep[f] + 1;
  par[0][u] = f;
  siz[u] = 1;
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i];
    if(v == f) continue;
    dfs(v,u);
    siz[u] += siz[v];
  }
}
void par_ini(){
  for(int i = 1;i <= 11;i++){
    for(int u = 1;u <= n;u++){
      par[i][u] = par[i - 1][par[i - 1][u]];
    }
  }
}
int kth_par(int u,int k){
  for(int i = 0;i <= 11;i++) if(k & (1 << i)) u = par[i][u];
  return u;
}
int lca(int u,int v){
	if(dep[u] < dep[v]) swap(u,v);
	u = kth_par(u,dep[u] - dep[v]);
	if(u == v) return u;
	for(int i = 11;i >= 0;i--){
		if(par[i][u] ^ par[i][v]){
			u = par[i][u];
			v = par[i][v];
		}
	}
	return par[0][u];
}
ll f[maxn][maxn];
vector <P> paths;
bool cmp(P a,P b){
  return dis[a.first][a.second] < dis[b.first][b.second];
}
int main(){
  n = getint();
  for(int i = 1;i < n;i++){
    int u = getint(), v = getint();
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,0);
  par_ini();
  for(int i = 1;i <= n;i++){
    for(int j = i + 1;j <= n;j++){
      dis[i][j] = dep[i] + dep[j] - (dep[lca(i,j)] << 1);
      paths.push_back(mp(i,j));
    }
  }
  sort(paths.begin(),paths.end(),cmp);
  for(int i = 0;i < (int)paths.size();i++){
    int u = paths[i].first, v = paths[i].second;
    if(dep[u] < dep[v]) swap(u,v);
    int a = lca(u,v);
    if(v == a){
      int vv = kth_par(u,dep[u] - dep[v] - 1);
      f[u][v] = max(f[u][vv],f[v][par[0][u]]) + siz[u] * (n - siz[vv]);
    }else{
      f[u][v] = max(f[u][par[0][v]],f[v][par[0][u]]) + siz[u] * siz[v];
    }
    f[v][u] = f[u][v];
  }
  ll ans = 0;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      ans = max(ans,f[i][j]);
    }
  }
  putll(ans,'\n');
  bufo.flush();
  return 0;
}