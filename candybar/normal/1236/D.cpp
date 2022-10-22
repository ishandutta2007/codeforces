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
#define maxm 100005
int n,m,k;
int up,down,lef,rig;
vector <int> blo_row[maxn],blo_col[maxm];
ll cnt;
void run(int x,int y,int dir){
  if(dir == 0){
    int pos = *lower_bound(blo_row[x].begin(),blo_row[x].end(),y);
    pos = min(pos,rig);
    if(pos == y) return;
    cnt += pos - y;
    up = x;
    run(x + 1,pos - 1,(dir + 1) % 4);
  }
  if(dir == 1){
    int pos = *lower_bound(blo_col[y].begin(),blo_col[y].end(),x);
    pos = min(pos,down);
    if(pos == x) return;
    cnt += pos - x;
    rig = y;
    run(pos - 1,y - 1,(dir + 1) % 4);
  }
  if(dir == 2){
    int pos = *(upper_bound(blo_row[x].begin(),blo_row[x].end(),y) - 1);
    pos = max(pos,lef);
    if(pos == y) return;
    cnt += y - pos;
    down = x;
    run(x - 1,pos + 1,(dir + 1) % 4);
  }
  if(dir == 3){
    int pos = *(upper_bound(blo_col[y].begin(),blo_col[y].end(),x) - 1);
    pos = max(pos,up);
    if(pos == x) return;
    cnt += x - pos;
    lef = y;
    run(pos + 1,y + 1,(dir + 1) % 4);
  }
}
int main(){
  n = getint(), m = getint(), k = getint();
  for(int i = 1;i <= k;i++){
    int x = getint(), y = getint();
    blo_row[x].push_back(y);
    blo_col[y].push_back(x);
  }
  for(int i = 1;i <= n;i++){
    blo_row[i].push_back(0);
    blo_row[i].push_back(m + 1);
    sort(blo_row[i].begin(),blo_row[i].end());
  }
  for(int i = 1;i <= m;i++){
    blo_col[i].push_back(0);
    blo_col[i].push_back(n + 1);
    sort(blo_col[i].begin(),blo_col[i].end());
  }
  down = n + 1, rig = m + 1;
  run(1,1,0);
  if(cnt + k == (ll)n * m) puts("Yes");
  else puts("No");
  return 0;
}