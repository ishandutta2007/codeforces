#include <cstdio>
#include <stdint.h>

int64_t as[200005];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=2;i<=N;i+=2){
    int X;
    scanf("%d",&X);
    int64_t& prev=as[i-1];
    int64_t& curr=as[i];
    prev=curr=as[i-2]+1;
    while(true){
      int64_t diff=curr*curr-prev*prev;
      if(diff<X){
	curr++;
      }else if(diff>X){
	prev++;
      }else{
	break;
      }
      if(curr>2e5){
	printf("No\n");
	return 0;
      }
    }
  }
  printf("Yes\n");
  for(int i=1;i<=N;i++){
    if(i>1) printf(" ");
    printf("%I64d",as[i]*as[i]-as[i-1]*as[i-1]);
  }
  printf("\n");
  return 0;
}