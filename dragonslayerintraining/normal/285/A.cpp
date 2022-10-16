#include <cstdio>
#include <vector>

std::vector<int> v;

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  for(int i=K+1;i>0;i--){
    v.push_back(i);
  }
  for(int i=K+2;i<=N;i++){
    v.push_back(i);
  }
  for(int i=0;i<N;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",v[i]);
  }
  printf("\n");
  return 0;
}