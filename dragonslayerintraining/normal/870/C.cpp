#include <cstdio>

int main(){
  int Q;
  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    int N;
    scanf("%d",&N);
    if(N%2==1){
      if((N<9)||(N==11)){
	printf("-1\n");
      }else{
	printf("%d\n",(N-9)/4+1);
      }
    }else{
      if(N==2){
	printf("-1\n");
      }else{
	printf("%d\n",N/4);
      }
    }
  }
  return 0;
}