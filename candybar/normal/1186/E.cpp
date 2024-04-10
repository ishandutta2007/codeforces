#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <cassert>
#define maxn 2005

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  char s[LEN + 5]; int len,it;
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
    if(len == LEN) fwrite(s,1,LEN,stdout), len = 0;
    s[len++] = c;
  }
  void flush(){
    fwrite(s,1,len,stdout);
    len = 0;
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get())
    res = (res << 3) + (res << 1) + (c - '0');
  return sig * res;
}
inline int getbit(){
  char c;
  for(c = buff.get();c < '0' || c > '1';c = buff.get());
  return c - '0';
}
inline void putll(ll x){
  if(!x) bufo.put('0');
  else if(x < 0) bufo.put('-'), x = -x;
  char s[25]; int k = 0;
  while(x){
    s[++k] = x % 10 + '0';
    x /= 10;
  }
  for(int i = k;i >= 1;i--) bufo.put(s[i]);
}

int n,m,q,a[maxn][maxn],sum[maxn][maxn];
vector <int> ms,ns;
ll calc(int inv,int x,int y){
  if(x < 1 || y < 1) return 0;
  if(x <= (n << 1) && y <= (m << 1))
    return inv ? x * y - sum[x][y] : sum[x][y];
  int x1 = *upper_bound(ns.begin(),ns.end(),x) >> 1;
  int y1_ = *upper_bound(ms.begin(),ms.end(),y) >> 1;
  if(x1 >= (n << 1)) return ((ll)x1 * y >> 1) + calc(inv ^ 1,x - x1,y);
  assert(y1_ >= (m << 1));
  return ((ll)x * y1_ >> 1) + calc(inv ^ 1,x,y - y1_);
}
int main(){
  n = getint(), m = getint(), q = getint();
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= m;j++){
      a[i + n][j + m] = a[i][j] = getbit();
      a[i + n][j] = a[i][j + m] = a[i][j] ^ 1;
    }
  }
  for(int i = 1;i <= (n << 1);i++){
    for(int j = 1;j <= (m << 1);j++){
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  }
  for(ll i = m;i <= (ll)2e9;i <<= 1ll) ms.push_back(i);
  for(ll i = n;i <= (ll)2e9;i <<= 1ll) ns.push_back(i);
  while(q--){
    int x1 = getint(), y1_ = getint(), x2 = getint(), y2 = getint();
    putll(calc(0,x1 - 1,y1_ - 1) - calc(0,x2,y1_ - 1) - calc(0,x1 - 1,y2) + calc(0,x2,y2));
    bufo.put('\n');
  }
  bufo.flush();
  return 0;
}