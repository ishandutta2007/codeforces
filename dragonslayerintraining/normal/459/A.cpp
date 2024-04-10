#include <cstdio>
#include <algorithm>

int main(){
  int X1,Y1,X2,Y2;
  scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
  if(std::abs(X1-X2)==std::abs(Y1-Y2)){
    printf("%d %d ",X1,Y2);
    printf("%d %d\n",X2,Y1);
  }else if(X1==X2){
    int side=Y1-Y2;
    printf("%d %d ",X1+side,Y1);
    printf("%d %d\n",X1+side,Y2);
  }else if(Y1==Y2){
    int side=X1-X2;
    printf("%d %d ",X1,Y1+side);
    printf("%d %d\n",X2,Y1+side);
  }else{
    printf("-1\n");
  }
  return 0;
}