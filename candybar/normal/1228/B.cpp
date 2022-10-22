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
#define mod 1000000007
#define maxn 1005
int h,w,r[maxn],c[maxn],col[maxn][maxn];
//2: empty, 1: full, 3: bad
int main(){
  h = getint(), w = getint();
  for(int i = 1;i <= h;i++){
    r[i] = getint();
    for(int j = 1;j <= r[i];j++) col[i][j] += 1;
    if(r[i] < w) col[i][r[i] + 1] += 3;
  }
  for(int i = 1;i <= w;i++){
    c[i] = getint();
    for(int j = 1;j <= c[i];j++) col[j][i] += 1;
    if(c[i] < h) col[c[i] + 1][i] += 3;
  }
  int ans = 1;
  for(int i = 1;i <= h;i++){
    for(int j = 1;j <= w;j++){
      if(col[i][j] == 4){
        putint(0,'\n');
        bufo.flush();
        return 0;
      }else if(!col[i][j]){
        ans = ans * 2 % mod;
      }
    }
  }
  putint(ans,'\n');
  bufo.flush();
  return 0;
}