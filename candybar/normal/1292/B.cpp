#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>
#define maxn 60

using namespace std;
typedef long long ll;
const ll LIM = 20000000000000000;

int n;
ll x[maxn],y[maxn],ax,ay,bx,by,xs,ys,t;
ll dis(int i,int j){
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
int main(){
  scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&x[0],&y[0],&ax,&ay,&bx,&by);
  scanf("%I64d%I64d%I64d",&xs,&ys,&t);
  for(n = 1;n <= 60;n++){
    x[n] = x[n - 1] * ax + bx, y[n] = y[n - 1] * ay + by;
    if(x[n] > LIM || y[n] > LIM) break;
  }
  int ans = 0;
  for(int i = 0;i < n;i++){
    ll rst = t - (abs(x[i] - xs) + abs(y[i] - ys));
    for(int j = 0;j < n;j++){
      for(int k = 0;k < n;k++){
        if(dis(i,j) + dis(j,k) <= rst) ans = max(ans,abs(j - k) + 1);
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}