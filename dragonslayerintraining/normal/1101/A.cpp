#include <cstdio>

int main(){
  int Q;
  scanf("%d",&Q);
  while(Q-->0){
    int L,R,D;
    scanf("%d %d %d",&L,&R,&D);
    printf("%d\n",(D<L)?D:(R/D+1)*D);
  }
  return 0;
}