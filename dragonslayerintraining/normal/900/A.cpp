#include <cstdio>

int side[2];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    side[X>0]++;
  }
  if((side[0]<=1)||(side[1]<=1)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}