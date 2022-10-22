#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#include <map>
#define maxn 200005
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
struct Point{
  int x,y;
  bool operator < (const Point &p)const
  {
    if(y == p.y) return x < p.x;
    return y < p.y;
  }
}p[maxn];
int n,maxx;
int bit_cnt[maxn];//0 or 1
void add(int pos,int x){
  for(int i = pos;i <= maxx;i += i & -i) bit_cnt[i] += x;
}
int query(int pos){
  int res = 0;
  for(int i = pos;i;i -= i & -i) res += bit_cnt[i];
  return res;
}
vector <int> xs,ys;
int varcnt[maxn];// > 1 ok.
int main(){
  n = getint();
  for(int i = 1;i <= n;i++){
    p[i].x = getint(), p[i].y = getint();
    xs.push_back(p[i].x);
    ys.push_back(p[i].y);
  }
  sort(xs.begin(),xs.end());
  xs.erase(unique(xs.begin(),xs.end()),xs.end());
  maxx = xs.size();
  for(int i = 1;i <= n;i++){
    p[i].x = lower_bound(xs.begin(),xs.end(),p[i].x) - xs.begin() + 1;
    varcnt[p[i].x]++;
    if(varcnt[p[i].x] == 1) add(p[i].x,1);
  }
  sort(ys.begin(),ys.end());
  ys.erase(unique(ys.begin(),ys.end()),ys.end());
  int st = 1;
  sort(p + 1,p + n + 1);
  ll ans = 0;
  for(int i = 0;i < (int)ys.size();i++){
    while(st <= n && p[st].y < ys[i]){
      varcnt[p[st].x]--;
      if(varcnt[p[st].x] == 0){
        add(p[st].x,-1);
      }
      st++;
    }
    int lst = 1;
    for(int j = st;j <= n && p[j].y == p[st].y;j++){
      int sum = query(p[j].x - 1) - query(lst - 1);
      ans -= (ll)(sum + 1) * sum / 2;
      lst = p[j].x + 1;
    }
    int sum = query(maxx) - query(lst - 1);
    ans -= (ll)(sum + 1) * sum / 2;
    sum = query(maxx);
    ans += (ll)(sum + 1) * sum / 2;
  }
  putll(ans);
  bufo.flush();
  return 0;
}