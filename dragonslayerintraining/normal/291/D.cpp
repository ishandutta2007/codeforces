#include <cstdio>

int as[10000];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int k=0;k<K;k++){
    for(int i=0;i<N;i++){
      if(i<(1<<k)){
	as[i]=0;
      }else if(i<(1<<(k+1))){
	as[i]=i-(1<<k);
      }else{
	as[i]=(1<<k);
      }
    }
    for(int i=0;i<N;i++){
      if(i>0){
	printf(" ");
      }
      printf("%d",N-as[N-1-i]);
    }
    printf("\n");
  }
  return 0;
}