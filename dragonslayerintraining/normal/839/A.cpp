#include <cstdio>
#include <algorithm>

int save=0;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    save+=A;
    int give=std::min(8,save);
    K-=give;
    save-=give;
    if(K<=0){
      printf("%d\n",i+1);
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}