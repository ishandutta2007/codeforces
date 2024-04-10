#include <cstdio>
#include <algorithm>

int main(){
  int X1,X2,A,B;
  scanf("%d %d %d %d",&X1,&X2,&A,&B);
  int X=X2-X1;
  if(X<0){
    X=-X;
    A=-A;
    B=-B;
    std::swap(A,B);
  }
  if(A<=0){
    if(X<=B){
      printf("FIRST\n%d\n",X2);
    }else{
      printf("DRAW\n");
    }
  }else{
    X%=(A+B);
    if(X==0){
      printf("SECOND\n");
    }else if(X>=A&&X<=B){
      printf("FIRST\n%d\n",X1+((X2>X1)?X:-X));
    }else{
      printf("DRAW\n");
    }
  }
  return 0;
}