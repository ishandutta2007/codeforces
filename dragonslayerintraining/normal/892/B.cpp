#include <cstdio>
#include <algorithm>

int ls[1000000];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&ls[i]);
  }
  std::reverse(ls,ls+N);
  int far=-1;
  int alive=0;
  for(int i=0;i<N;i++){
    if(i>far){
      alive++;
    }
    far=std::max(far,i+ls[i]);
  }
  printf("%d\n",alive);
  return 0;
}