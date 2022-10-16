#include <cstdio>
#include <algorithm>

int min=0,max=0;

int cost=0;

int main(){
  int N,D;
  scanf("%d %d",&N,&D);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A!=0){
      min+=A;
      max+=A;
      max=std::min(max,D);
      if(min>D){
	printf("-1\n");
	return 0;
      }
    }else{
      min=std::max(min,0);
      if(max<0){
	cost++;
	max=D;
      }
    }
  }
  printf("%d\n",cost);
  return 0;
}