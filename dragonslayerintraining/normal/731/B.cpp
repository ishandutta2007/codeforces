#include <cstdio>
#include <cstdlib>

int as[200000];

void fail(){
  printf("NO\n");
  exit(0);
}

int main(){
  int N;
  scanf("%d",&N);
  int coupon=0;
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
    if(coupon&&as[i]==0) fail();
    as[i]-=coupon;
    coupon=0;
    as[i]%=2;
    coupon^=as[i];
  }
  if(coupon) fail();
  printf("YES\n");
  return 0;
}