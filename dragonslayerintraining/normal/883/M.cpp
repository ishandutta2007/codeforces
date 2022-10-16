#include <cstdio>
#include <cmath>

int main(){
  int X1,Y1,X2,Y2;
  scanf("%d %d %d %d",&X1,&Y1,&X2,&Y2);
  int dx=std::abs(X1-X2);
  int dy=std::abs(Y1-Y2);
  printf("%d\n",2*(dx+dy+(dx==0)+(dy==0))+4);
  return 0;
}