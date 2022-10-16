#include <cstdio>

int minute[1000000];

int main(){
  int K,N,M;
  scanf("%d %d %d",&N,&M,&K);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    minute[A-1]++;
  }
  int ring=0;
  int off=0;
  for(int i=0;i<1000000;i++){
    ring+=minute[i];
    if(i>=M){
      ring-=minute[i-M];
    }
    if(ring>=K){
      minute[i]--;
      ring--;
      off++;
    }
  }
  printf("%d\n",off);
  return 0;
}