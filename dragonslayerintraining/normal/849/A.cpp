#include <cstdio>

int as[100];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if((N%2==1)&&(as[0]%2==1)&&(as[N-1]%2==1)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
}