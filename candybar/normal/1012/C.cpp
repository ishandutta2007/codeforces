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
#define maxn 5005
int n,a[maxn],f[maxn][2505][2];
int cst(int x,int y){// height x down to height y
  if(x < y) return 0;
  return x - y + 1;
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  memset(f,0x3f,sizeof(f));
  f[0][0][0] = f[1][0][0] = f[1][1][1] = 0;
  for(int i = 2;i <= n;i++){
    f[i][0][0] = 0;
    for(int j = 1;j <= ((n + 1) >> 1);j++){
      f[i][j][0] = min(f[i - 1][j][1] + cst(a[i],a[i - 1]),f[i - 1][j][0]);
      f[i][j][1] = min(f[i - 2][j - 1][0] + cst(a[i - 1],a[i]),f[i - 2][j - 1][1] + cst(a[i - 1],min(a[i - 2],a[i])));
    }
  }
  for(int i = 1;i <= ((n + 1) >> 1);i++)
    putint(min(f[n][i][0],f[n][i][1]),i == ((n + 1) >> 1) ? '\n' : ' ');
  bufo.flush();
  return 0;
}