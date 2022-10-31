#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <utility>

using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

int main() {
  int n,k;
  scanf("%d%d",&n,&k);
  if(n==1) {
    if(k==0) printf("1\n");
    else printf("-1\n");
    return 0;
  }
  if(n/2 > k) {
    printf("-1\n");
    return 0;
  }
  int a = k-(n/2-1);
  int b = 2*a;
  printf("%d %d",a,b);
  int ctr = 1;
  for(int i = 1; i < n/2; ++i) {
    while(ctr==a || ctr==b || ctr+1==a || ctr+1==b) ++ctr;
    printf(" %d %d",ctr,ctr+1);
    ctr+=2;
  }
  if(n&1) printf(" 1000000000\n");
  else printf("\n");
}