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
#define maxn 1000005
int n;
ll k;
vector <int> use,unuse;
void choose(ll x,ll num,ll tar){
  if(x > n) return;
  if(n - x + 1 == num){
    use.push_back(x);
    choose(x + 1,num - 1,tar - x);
    return;
  }
  ll sum = (x + 1 + x + num) * num / 2;
  if(sum <= tar){
    unuse.push_back(x);
    choose(x + 1,num,tar);
  }else{
    use.push_back(x);
    choose(x + 1,num - 1,tar - x);
  }
}
int main(){
  n = getint(), k = getll();
  if(k < ll(1 + n) * n / 2){
    puts("-1");
    return 0;
  }
  ll sum1 = 0, num1 = 0;
  for(int i = n / 2 + 1;i <= n;i++){
    num1++;
    sum1 += i;
  }
  ll num2 = n - num1, maxsum2 = 0;
  for(int i = n;i >= n - num2 + 1;i--) maxsum2 += i;
  k = min(k,sum1 + maxsum2);
  choose(1,num2,k - sum1);
  printf("%I64d\n",k);
  vector <int> p,q;
  for(int i = 0;i < num1;i++){
    p.push_back(n - num1 + i + 1);
    q.push_back(unuse[i]);
  }
  for(int i = 0;i < num2;i++){
    p.push_back(i + 1);
    q.push_back(use[i]);
  }
  for(int i = 0;i < n;i++){
    printf("%d%c",p[i],i == n - 1 ? '\n' : ' ');
  }
  for(int i = 0;i < n;i++){
    printf("%d%c",q[i],i == n - 1 ? '\n' : ' ');
  }
  return 0;
}