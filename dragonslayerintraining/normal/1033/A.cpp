#include <cstdio>

int xs[3],ys[3];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<3;i++){
    scanf("%d %d",&xs[i],&ys[i]);
  }
  if((xs[1]>xs[0])==(xs[2]>xs[0])&&
     (ys[1]>ys[0])==(ys[2]>ys[0])){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  return 0;
}