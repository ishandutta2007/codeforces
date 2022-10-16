#include <cstdio>
#include <cmath>

int main(){
  int X,Y,Z,T1,T2,T3;
  scanf("%d %d %d %d %d %d",&X,&Y,&Z,&T1,&T2,&T3);
  printf("%s\n",(std::abs(X-Y)*T1>=(std::abs(Z-X)+std::abs(X-Y))*T2+3*T3)?"YES":"NO");
  return 0;
}