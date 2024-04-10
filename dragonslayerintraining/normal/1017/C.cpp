#include <cstdio>
#include <vector>

int main(){
  int N;
  scanf("%d",&N);
  int x=1,y=1;
  while(true){
    if(x*y<N) x++; else break;
    if(x*y<N) y++; else break;
  }
  std::vector<int> ps;
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      int v=j*x+x-i;
      if(v<=N){
	printf("%d ",v);
      }
    }
  }
  printf("\n");
  return 0;
}