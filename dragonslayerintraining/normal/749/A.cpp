#include <cstdio>
#include <vector>

std::vector<int> vs;

int main(){
  int N;
  scanf("%d",&N);
  if(N%2){
    vs.push_back(3);
    N-=3;
  }
  for(;N>0;N-=2){
    vs.push_back(2);
  }
  printf("%d\n",(int)vs.size());
  for(int i=0;i<vs.size();i++){
    if(i) printf(" ");
    printf("%d",vs[i]);
  }
  printf("\n");
  return 0;
}