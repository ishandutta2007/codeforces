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
#define maxn 200005
int n,a[maxn],q;
struct query{
  int fl,p,x;
}qs[maxn];
bool have_set[maxn];
int max2,res[maxn];
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  q = getint();
  for(int i = 1;i <= q;i++){
    qs[i].fl = getint();
    if(qs[i].fl == 1){
      qs[i].p = getint(), qs[i].x = getint();
    }else{
      qs[i].x = getint();
    }
  }
  for(int i = q;i >= 1;i--){
    if(qs[i].fl == 2) max2 = max(max2,qs[i].x);
    else if(!have_set[qs[i].p]){
      res[qs[i].p] = max(max2,qs[i].x);
      have_set[qs[i].p] = true;
    }
  }
  for(int i = 1;i <= n;i++){
    if(!have_set[i]){
      res[i] = max(a[i],max2);
      have_set[i] = true;
    }
    putint(res[i]);
    bufo.put(i == n ? '\n' : ' ');
  }
  bufo.flush();
  return 0;
}