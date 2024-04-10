#include <cstdio>
#include <algorithm>

int as[100];

int main(){
  int N,K,X;
  scanf("%d %d %d",&N,&K,&X);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  for(int i=N-1;i>=N-K;i--){
    as[i]=std::min(as[i],X);
  }
  int total=0;
  for(int i=0;i<N;i++){
    total+=as[i];
  }
  printf("%d\n",total);
  return 0;
}