#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100005
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
}buff;
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
int n,a[maxn];

int main(){
  n = getint();
  bool not0 = false;
  for(int i = 1;i <= n;i++){
    a[i] = getint();
    if(a[i]) not0 = true;
  }
  if(!not0){
    puts("cslnb");
    return 0;
  }
  if(n == 1){
    if(a[1] & 1) puts("sjfnb");
    else puts("cslnb");
    return 0;
  }
  sort(a + 1,a + n + 1);
  int same = 0, pos = 0;
  for(int i = 1;i < n;i++){
    same += (a[i] == a[i + 1]);
    if(a[i] == a[i + 1]) pos = i;
  }
  if(same >= 2){
    puts("cslnb");
    return 0;
  }
  if(same == 1){
    if(a[pos] == 0 || (pos > 1 && a[pos - 1] == a[pos] - 1)){
      puts("cslnb");
      return 0;
    }
  }
  int res = 0;
  for(int i = 1;i <= n;i++){
    res ^= ((a[i] - (i - 1)) & 1);
  }
  if(res) puts("sjfnb");
  else puts("cslnb");
  return 0;
}