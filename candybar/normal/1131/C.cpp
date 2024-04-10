#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 105
using namespace std;
typedef long long ll;
inline int getint(){
  char c; int res = 0;
  for(c = getchar();c < '0' || c > '9';c = getchar());
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res;
}
const int inf = 0x3f3f3f3f;
int n,a[maxn];
int b[maxn],k;
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  sort(a + 1,a + n + 1);
  if(n & 1){
    for(int i = n;i >= 1;i -= 2){
      printf("%d ",a[i]);
    }
    for(int i = 2;i <= n;i += 2){
      printf("%d ",a[i]);
    }
    printf("\n");
  }else{
    for(int i = 1;i <= n;i += 2){
      printf("%d ",a[i]);
    }
    for(int i = n;i >= 1;i -= 2){
      printf("%d ",a[i]);
    }
    printf("\n");
  }
  return 0;
}