#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#include <set>

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
inline void putint(int x){
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
}
inline void putll(ll x){
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
}
inline char get_char(){
  char c;
  for(c = buff.get();c == ' ' || c == '\n';c = buff.get());
  return c;
}
#define maxn 100005
#define mp make_pair
typedef pair<int,int> P;
int T,n,m,k;
vector <P> adj[maxn * 3];//to,id
bool vis[maxn * 3];
int nxtnode(){
  while(k <= n * 3 && vis[k]) k++;
  return k;
}
struct edge{
  int from,to,id;
  bool operator < (const edge &b)const
  {
    return to > b.to;
  }
};
void work(){
  priority_queue <edge> que;
  //to > from
  vector <int> mat;
  k = 1;
  set <int> S;
  for(int i = 1;i <= 3 * n;i++){
    if(!que.empty()){
      edge e = que.top();
      mat.push_back(e.id);
      vis[e.from] = vis[e.to] = true;
      S.erase(e.from);
      while(!que.empty()) que.pop();
    }else{
      int u = nxtnode(); k++;
      S.insert(u);
      for(int i = 0;i < (int)adj[u].size();i++){
        int v = adj[u][i].first;
        if(!vis[v]){
          que.push((edge){u,v,adj[u][i].second});
        }
      }
    }
  }
  if((int)mat.size() >= n){
    puts("Matching");
    for(int i = 0;i < n;i++){
      printf("%d%c",mat[i],i == n - 1 ? '\n' : ' ');
    }
  }else{
    puts("IndSet");
    for(int i = 0;i < n;i++){
      printf("%d%c",*S.begin(),i == n - 1 ? '\n' : ' ');
      S.erase(*S.begin());
    }
  }
}
int main(){
  T = getint();
  while(T--){
    n = getint(), m = getint();
    for(int i = 1;i <= n * 3;i++) adj[i].clear(), vis[i] = 0;
    for(int i = 1;i <= m;i++){
      int u = getint(), v = getint();
      if(u > v) swap(u,v);
      adj[u].push_back(mp(v,i));
    }
    work();
  }
  return 0;
}