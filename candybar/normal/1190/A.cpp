#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxm 100005
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
inline ll getll(){
  char c; ll res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get())
    res = (res << 3) + (res << 1) + (c - '0');
  return sig * res;
}
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get())
    res = (res << 3) + (res << 1) + (c - '0');
  return sig * res;
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
inline void putint(int x){
  if(!x) bufo.put('0');
  else if(x < 0) bufo.put('-'), x = -x;
  char s[15]; int k = 0;
  while(x){
    s[++k] = x % 10 + '0';
    x /= 10;
  }
  for(int i = k;i >= 1;i--) bufo.put(s[i]);
}

ll p[maxm],n,k;
int m,del;
bool same(ll a,ll b){
  // assert all the deleted item is before p and q.
  return (p[a] - del) / k == (p[b] - del) / k;
}
int main(){
  n = getll(), m = getint(), k = getll();
  for(int i = 1;i <= m;i++) p[i] = getll() - 1;
  int ed = 1, ans = 0;
  for(int i = 1;i <= m;i = ed){
    while(ed <= m && same(i,ed)) ed++;
    del += ed - i;
    ans++;
  }
  putint(ans);
  bufo.flush();
  return 0;
}