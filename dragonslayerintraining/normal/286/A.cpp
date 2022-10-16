#include <cstdio>

int ps[100000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N/2;i+=2){
    ps[i]=i+1;
    ps[i+1]=N-1-i;
    ps[N-1-i]=N-i-2;
    ps[N-2-i]=i;
  }
  if(N%4==1){
    ps[N/2]=N/2;
  }
  if(N%4<2){
    for(int i=0;i<N;i++){
      if(i>0){
	printf(" ");
      }
      printf("%d",ps[i]+1);
    }
    printf("\n");
  }else{
    printf("-1\n");
  }
  return 0;
}