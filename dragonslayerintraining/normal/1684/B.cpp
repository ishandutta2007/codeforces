#include <cstdio>

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    printf("%lld %d %d\n",A+1LL*B*C,B,C);
  }
}