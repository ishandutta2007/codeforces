#include <cstdio>
#include <algorithm>

int as[100000];

int main(){
  int K,N;
  scanf("%d %d",&N,&K);
  for(int i=0;i<N;i++){
    scanf("%d",&as[i]);
  }
  if(K==1){
    printf("%d\n",*std::min_element(as,as+N));
  }else if(K>=3){
    printf("%d\n",*std::max_element(as,as+N));
  }else{
    printf("%d\n",std::max(as[0],as[N-1]));
  }
  return 0;
}