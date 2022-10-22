#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 200005
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,a[maxn],b[maxn];
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  for(int i = 1;i <= n;i++) b[i] = getint();
  bool ok = true;
  int i;
  for(i = n - 1;i >= 1 && n - i <= b[n];i--){
    if(b[i] + n - i != b[n]){
      ok = false;
      break;
    }
  }
  for(;i >= 1;i--){
    if(b[i] && i > b[i] - b[n] - 1){
      ok = false;
      break;
    }
  }
  if(ok){
    printf("%d\n",n - b[n]);
    return 0;
  }
  int ans = 0;
  for(i = 1;i <= n;i++){
    if(b[i]) ans = max(ans,i - b[i]);
  }
  printf("%d\n",ans + n + 1);
  return 0;
}