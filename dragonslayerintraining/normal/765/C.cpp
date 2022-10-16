#include <cstdio>

int main(){
  int K,A,B;
  scanf("%d %d %d",&K,&A,&B);
  int X=A/K,Y=B/K;
  if(A<=X*K+(K-1)*Y&&
     B<=Y*K+(K-1)*X){
    printf("%d\n",X+Y);
  }else{
    printf("-1\n");
  }
  return 0;
}