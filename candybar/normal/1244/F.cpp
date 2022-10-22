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
#define maxn 200005
int n,k;
char s[maxn],t[maxn];
bool firm[maxn];
inline int black(int pos){
  return s[(pos + n) % n] == 'B' ? 1 : 0;
}
int main(){
  scanf("%d%d",&n,&k);
  scanf("%s",s);
  int st = -1, firm_cnt = 0;
  for(int i = 0;i < n;i++)
    if(s[(i + n - 1) % n] == s[i] || s[i] == s[(i + 1) % n]){
      firm[i] = true;
      firm_cnt++;
      if(st == -1) st = i;
    }
  if(firm_cnt == n){
    printf("%s\n",s);
    return 0;
  }
  if(st == -1){
    for(int i = 0;i < n;i++){
      if(k & 1) printf("%c",s[i] == 'B' ? 'W' : 'B');
      else printf("%c",s[i]);
    }
    printf("\n");
    return 0;
  }
  
//  cout << st << " " << firm_cnt << endl;
//  for(int i = 0;i < n;i++) cout << firm[i] << " ";
//  cout << endl;
//  system("pause");
  
  int i = st;
  while(i < n + st){
    while(firm[i % n]) i++;
    int j = i;
    while(!firm[j % n]) j++;
    j--;
    for(int l = i;l <= j;l++){
      int alive, final;
      if(l - i <= j - l){
        alive = l - i + 1;
        final = black(i - 1);
      }else{
        alive = j - l + 1;
        final = black(j + 1);
      }
      if(k <= alive) t[l % n] = ((k & 1) ^ black(l)) ? 'B' : 'W';
      else t[l % n] = final ? 'B' : 'W';
    }
    i = j + 1;
  }
  for(int i = 0;i < n;i++) printf("%c",firm[i] ? s[i] : t[i]);
  printf("\n");
  return 0;
}