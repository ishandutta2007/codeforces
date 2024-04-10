#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1000005
using namespace std;
typedef long long ll;

char a[maxn],b[maxn];
int alen,blen;
int main(){
  scanf("%s",a); alen = strlen(a);
  scanf("%s",b); blen = strlen(b);
  int ans = 0, cur = 1, inn = 0;
  for(int i = 0;i < blen;i++){
    cur ^= (a[i] - '0') ^ (b[i] - '0');
    if(i > 0 && b[i] ^ b[i - 1]) inn ^= 1;
  }
  ans += cur;
  for(int i = 1;i <= alen - blen;i++){
    cur ^= inn;
    if(a[i - 1] ^ b[0]) cur ^= 1;
    if(a[i + blen - 1] ^ b[blen - 1]) cur ^= 1;
    ans += cur;
  }
  printf("%d\n",ans);
  return 0;
}