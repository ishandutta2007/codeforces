#include <cstdio>
#include <algorithm>

int main(){
  int Y,B,R;
  scanf("%d %d %d",&Y,&B,&R);
  int x=std::min(Y,std::min(B-1,R-2));
  printf("%d\n",x+(x+1)+(x+2));
  return 0;
}