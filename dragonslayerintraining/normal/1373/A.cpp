#include <cstdio>

int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    printf("%d %d\n",(A<C)?1:-1,(1LL*A*B>C)?B:-1);
  }
}