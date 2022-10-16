#include <cstdio>
#include <vector>

int main(){
  int N,K;
  scanf("%d %d",&N,&K);
  int low=1,high=N;
  std::vector<int> vs;
  for(int k=1;k<=K;k++){
    if(k&1){
      vs.push_back(low++);
    }else{
      vs.push_back(high--);
    }
  }
  if(K&1){
    for(int i=low;i<=high;i++){
      vs.push_back(i);
    }
  }else{
    for(int i=high;i>=low;i--){
      vs.push_back(i);
    }
  }
  bool first=true;
  for(int v:vs){
    if(first) first=false; else printf(" ");
    printf("%d",v);
  }
  printf("\n");
  return 0;
}