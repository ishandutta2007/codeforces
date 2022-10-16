#include <cstdio>
#include <vector>

std::vector<int> vs[3];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    int A;
    scanf("%d",&A);
    if(A<0){
      vs[0].push_back(A);
    }else if(A>0){
      vs[1].push_back(A);
    }else{
      vs[2].push_back(A);
    }
  }
  if(vs[1].empty()){
    vs[1].push_back(vs[0].back());
    vs[0].pop_back();
    vs[1].push_back(vs[0].back());
    vs[0].pop_back();
  }
  if(vs[0].size()%2==0){
    vs[2].push_back(vs[0].back());
    vs[0].pop_back();
  }
  for(int k=0;k<3;k++){
    printf("%d",static_cast<int>(vs[k].size()));
    for(int v:vs[k]){
      printf(" %d",v);
    }
    printf("\n");
  }
  return 0;
}