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
#define maxn 500005
#define maxq 500005
#define mp make_pair
const ll infll = 0x3f3f3f3f3f3f3f3fll;
typedef pair<int,int> P;
int n,q,leaf[maxn],siz[maxn],lk;
vector <P> sons[maxn];// to,cst.
ll dis[maxn];
void dfs(int u){
  if(sons[u].empty()) leaf[++lk] = u;
  siz[u] = 1;
  for(int i = 0;i < (int)sons[u].size();i++){
    int v = sons[u][i].first;
    dis[v] = dis[u] + sons[u][i].second;
    dfs(v);
    siz[u] += siz[v];
  }
}
ll a[maxn << 2],add[maxn << 2];
void up(int id){
  a[id] = min(a[id << 1],a[id << 1 | 1]);
  a[id] += add[id];
}
void down(int id){
  if(add[id]){
    add[id << 1] += add[id];
    a[id << 1] += add[id];
    add[id << 1 | 1] += add[id];
    a[id << 1 | 1] += add[id];
    add[id] = 0;
  }
}
void build(int id,int l,int r){
  if(l == r){
    a[id] = dis[leaf[l]];
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1,l,mid);
  build(id << 1 | 1,mid + 1,r);
  up(id);
}
void update(int id,int l,int r,int ql,int qr,int x){
  if(ql <= l && r <= qr){
    add[id] += x;
    a[id] += x;
  }else{
    down(id);
    int mid = (l + r) >> 1;
    if(ql <= mid) update(id << 1,l,mid,ql,qr,x);
    if(mid < qr) update(id << 1 | 1,mid + 1,r,ql,qr,x);
    up(id);
  }
}
ll query(int id,int l,int r,int ql,int qr){
  if(ql <= l && r <= qr) return a[id];
  down(id);
  int mid = (l + r) >> 1; ll res = infll;
  if(ql <= mid) res = min(res,query(id << 1,l,mid,ql,qr));
  if(mid < qr) res = min(res,query(id << 1 | 1,mid + 1,r,ql,qr));
  return res;
}
void range_add(int l,int r,int x){
  int ll = lower_bound(leaf + 1,leaf + lk + 1,l) - leaf,
      rr = upper_bound(leaf + 1,leaf + lk + 1,r) - leaf - 1;
  if(ll <= rr) update(1,1,lk,ll,rr,x);
}
ll range_dis(int l,int r){
  int ll = lower_bound(leaf + 1,leaf + lk + 1,l) - leaf,
      rr = upper_bound(leaf + 1,leaf + lk + 1,r) - leaf - 1;
  return query(1,1,lk,ll,rr);
}
struct Query{
  int l,r,id;
};
vector <Query> qs[maxn];
ll ans[maxq];
void calc(int u){
  for(int i = 0;i < (int)qs[u].size();i++)
    ans[qs[u][i].id] = range_dis(qs[u][i].l,qs[u][i].r);
  for(int i = 0;i < (int)sons[u].size();i++){
    P e = sons[u][i];
    range_add(1,e.first - 1,e.second);
    range_add(e.first,e.first + siz[e.first] - 1,-e.second);
    range_add(e.first + siz[e.first],n,e.second);
    calc(e.first);
    range_add(1,e.first - 1,-e.second);
    range_add(e.first,e.first + siz[e.first] - 1,e.second);
    range_add(e.first + siz[e.first],n,-e.second);
  }
}
int main(){
  n = getint(), q = getint();
  for(int i = 2;i <= n;i++){
    int p = getint(), w = getint();
    sons[p].push_back(mp(i,w));
  }
  dfs(1);
  build(1,1,lk);
  for(int i = 1;i <= q;i++){
    int v = getint(), l = getint(), r = getint();
    qs[v].push_back((Query){l,r,i});
  }
  calc(1);
  for(int i = 1;i <= q;i++) putll(ans[i],'\n');
  bufo.flush();
  return 0;
}