#include <cstdio>

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    putchar('0'+(i&1));
  }
  printf("\n");
  return 0;
}