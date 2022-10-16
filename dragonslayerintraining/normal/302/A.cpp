#include <cstdio>

int X,Y;

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A==1){
      X++;
    }else{
      Y++;
    }
  }
  for(int i=0;i<M;i++){
    int L,R;
    scanf("%d %d",&L,&R);
    int Q=R-L+1;
    printf("%d\n",(Q%2==0)&&(X>=Q/2)&&(Y>=Q/2));
  }
  return 0;
}