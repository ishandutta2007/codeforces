#include <cstdio>
#include <algorithm>

int as[501];
int sel[501];

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  int total=0;
  for(int i=0;i<N;i++){
    sel[i]=std::max(sel[i],as[i]);
    sel[i+1]=std::max(0,K-sel[i]);
  }
  for(int i=0;i<N;i++){
    total+=std::max(0,sel[i]-as[i]);
  }
  printf("%d\n",total);
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",sel[i]);
  }
  printf("\n");
  return 0;
}