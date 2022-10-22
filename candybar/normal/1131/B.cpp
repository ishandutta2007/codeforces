#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}
int n,a,b;
int main(){
  n = getint();
  int ans = 1;
  for(int i = 1;i <= n;i++){
    int x = getint(), y = getint();
    if(a > b){
      if(y < a){
        b = y, a = x;
      }else{
        ans++;
        b = a;
        ans += min(x,y) - a;
        a = x, b = y;
      }
    }else if(a == b){
      ans += min(x,y) - a;
      a = x, b = y;
    }else{
      if(x < b){
        a = x, b = y;
      }else{
        ans++;
        a = b;
        ans += min(x,y) - a;
        a = x, b = y;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}