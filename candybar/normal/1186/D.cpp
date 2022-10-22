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

int n;
double a[maxn];
bool can_add1[maxn];
int b[maxn];
ll sum;
int main(){
  scanf("%d",&n);
  for(int i = 1;i <= n;i++){
    scanf("%lf",&a[i]);
    b[i] = floor(a[i]);
    sum += b[i];
    if(b[i] < ceil(a[i])) can_add1[i] = true;
  }
  for(int i = 1;i <= n;i++){
    if(sum < 0 && can_add1[i]) b[i]++, sum++;
  }
  for(int i = 1;i <= n;i++){
    printf("%d\n",b[i]);
  }
  return 0;
}